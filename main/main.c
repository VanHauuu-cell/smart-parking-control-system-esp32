#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "servo.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    ESP_LOGI(TAG, "Smart Parking Main Controller");

    ESP_ERROR_CHECK(servo_init());

    while (1)
    {
        ESP_LOGI(TAG, "ENTRY -> 0 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_ENTRY, 0)
        );

        ESP_LOGI(TAG, "EXIT -> 0 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_EXIT, 0)
        );

        vTaskDelay(pdMS_TO_TICKS(2000));

        ESP_LOGI(TAG, "ENTRY -> 90 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_ENTRY, 90)
        );

        ESP_LOGI(TAG, "EXIT -> 90 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_EXIT, 90)
        );

        vTaskDelay(pdMS_TO_TICKS(2000));

        ESP_LOGI(TAG, "ENTRY -> 180 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_ENTRY, 180)
        );

        ESP_LOGI(TAG, "EXIT -> 180 deg");
        ESP_ERROR_CHECK(
            servo_set_angle(SERVO_EXIT, 180)
        );

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}