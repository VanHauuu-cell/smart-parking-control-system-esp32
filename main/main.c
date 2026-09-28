#include "mfrc522.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "APP_MAIN";

void app_main(void) {
    if (mfrc522_init() == ESP_OK) {
        ESP_LOGI(TAG, "MFRC522 Khoi tao thanh cong!");
    } else {
        ESP_LOGE(TAG, "Loi khoi tao MFRC522!");
        return;
    }

    uint8_t tagType[2];
    uint8_t uid[5];

    while (1) {
        // Kiểm tra xem có thẻ không
        if (mfrc522_request(PICC_CMD_REQA, tagType) == MFRC522_STATUS_OK) {
            // Nếu có thẻ, đọc UID chống va chạm
            if (mfrc522_anticoll(uid) == MFRC522_STATUS_OK) {
                ESP_LOGI(TAG, "Phat hien the! UID: %02X:%02X:%02X:%02X", 
                         uid[0], uid[1], uid[2], uid[3]);
                
                // Tránh đọc liên tục 1 thẻ nhiều lần quá nhanh
                vTaskDelay(pdMS_TO_TICKS(1000)); 
            }
        }
        
        // Quét lại sau mỗi 100ms
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}