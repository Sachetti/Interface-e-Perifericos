# A Low Cost System of pH Level Monitoring Using Cabbage Essence
Projeto de Interface e Periféricos

Interface and Peripheral Project. 

A Low Cost System of pH Level Monitoring Using Cabbage Essence

This project implements a low cost system that identify the pH Scale by color code level in substances using cabbage juice. The main idea was monitoring the pH level from the lake of our universisty (Universidade Federal do Espírito Santo - Brazil) which is an habitat from many animals and high/low ph levels are lethal for these animals, forcing an involutary migration. The system also can be applied in many fields of science like river monitoring, lake monitoring, rain monitoring (acid rain), etc.

In our researchs we found many ph level monitoring devices but they have high costs, so we elaborate this solution based in a low cost natural product: the cabbage. When mixing cabbage juice with other substances like water, sodium bicarbonate, lemon, vinegar, etc, the mix changes his colour and we can measure the pH scale from the mix based in that colour using the following table.
![0_Our2597chDYx7i2r](https://user-images.githubusercontent.com/58694964/142466438-5a098d34-efdf-4a28-bf69-3282a805b21b.jpg)

The system also use a RGB colour sensor (TCS230) and an ESP8266 device (Wemos D1 Mini) to collect and send the datas from monitoring. The data is storaged in Thingspeak platform, which has a free plan for projects like this. The external luminosity interfers in the RGB sensor, so it was used a black box with the sensor and the mix to prevent that. 

![photo_2019-12-08_17-00-43 (2)](https://user-images.githubusercontent.com/58694964/142471141-7eeafd60-4ad5-4474-a0af-ac0316dbff98.jpg)
![photo_2019-12-08_17-00-46 (2)](https://user-images.githubusercontent.com/58694964/142471155-271e8582-8bc5-4fde-8165-0aeac9488d2b.jpg)

The best usage of the system is collecting the water from these environments and mixing with the cabbage essence some times per day, and this mixture is analyzed by the sensor. The data storaged in the platform can be analyzed using some machine learning algorithm in the future, like anomaly detection or time series prediction. For last we have a video showing the mixtures with the cabbage juice, we used water, lemon, vinegar and sodium bicarbonate, and the data was send to Thingspeak using the ESP8266 by wifi.


[![Watch the video](https://img.youtube.com/vi/4HbXtNFfKGo/sddefault.jpg)](https://www.youtube.com/watch?v=4HbXtNFfKGo)
