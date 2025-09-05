# 🚲 Ventilated Seat – Smart Cooling System

The **Ventilated Seat** is designed for **long-distance travelers and cyclists**, providing continuous airflow from the seat to enhance comfort and reduce fatigue.  
It prevents sweat build-up, improves cooling, and ensures a more comfortable journey during long rides or travels.  

---

## 📑 Table of Contents
1. [Project Overview](#-project-overview)  
2. [Features](#-features)  
3. [Block Diagram](#-block-diagram)  
4. [Working Principle](#-working-principle)  
5. [Bill of Materials (BOM)](#-bill-of-materials-bom)  
6. [Cost Estimation](#-cost-estimation)  
7. [Circuit Description](#-circuit-description)  
8. [Code Explanation](#-code-explanation)  
9. [How to Run](#-how-to-run)  
10. [Future Improvements](#-future-improvements)  

---

## 📖 Project Overview
The **Ventilated Seat System** uses a **temperature sensor (DS18B20)** to monitor seat temperature.  
When the temperature exceeds a set threshold (27°C in this design):  
- Cooling fans and a **Peltier module** are activated.  
- The cooling system reduces heat and provides airflow to the rider.  
- A **16x2 LCD** displays temperature readings and system status.  

This project is suitable for **cyclists, bikers, and long-distance travelers**, ensuring maximum comfort and reduced fatigue.  

---

## ✨ Features
- 🌡️ **Temperature Monitoring**: Real-time seat temperature via DS18B20 sensor.  
- ❄️ **Automatic Cooling**: Fans & Peltier activated when temperature crosses threshold.  
- 🔌 **Relay Controlled**: Safe switching of high-power devices.  
- 🖥️ **LCD Display**: User-friendly interface for temperature & cooling status.  
- ⚡ **Stable Power**: 7805 regulator ensures reliable 5V supply.  
- 🪑 **Ventilated Seat**: Provides airflow to prevent sweating & improve comfort.  

---

## 📊 Block Diagram
Temperature Sensor (DS18B20)
│
▼
Arduino Nano ─── LCD (16x2)
│
┌──────┴────────────┐
│ │
Relay L298N Driver
│ │
Peltier Module Cooling Fans


---

## ⚙️ Working Principle
1. **Temperature Monitoring**  
   - DS18B20 sensor measures seat temperature continuously.  

2. **Decision Making**  
   - If temperature > **27°C**, system turns **ON** cooling.  
   - If temperature ≤ **27°C**, system turns **OFF** cooling.  

3. **Cooling Action**  
   - Relay supplies power to **Peltier module**.  
   - L298N drives the **cooling fans**.  
   - LCD shows **Temp: XX°C** and **Cooling: ON/OFF**.  

4. **User Feedback**  
   - LCD keeps the rider updated about temperature and system state.  

---

## 📦 Bill of Materials (BOM) – *For 1 Module*
| Sl.no | Part Number | Category      | Component        | Qty | Unit Cost (₹) | Total Cost (₹) |
|-------|-------------|--------------|------------------|-----|---------------|----------------|
| 1     | –           | Switch       | SPDT Switch      | 1   | 9.00          | 9.00           |
| 2     | 7805        | Regulator    | 7805             | 1   | 8.00          | 8.00           |
| 3     | –           | Controller   | Arduino Nano     | 1   | 160.00        | 160.00         |
| 4     | DS18B20     | Sensor       | DS18B20          | 1   | 50.00         | 50.00          |
| 5     | L298N       | Motor Driver | L298N Module     | 1   | 85.00         | 85.00          |
| 6     | LCD16x2     | Display      | 16x2 LCD (I2C)   | 1   | 110.00        | 110.00         |
| 7     | –           | Fan          | CPU Fan          | 1   | 60.00         | 60.00          |
| 8     | –           | Relay        | 1-Channel Relay  | 1   | 55.00         | 55.00          |
| 9     | –           | Seat         | Ventilated Seat  | 1   | 761.00        | 761.00         |
| 10    | –           | Module       | Peltier          | 1   | 155.00        | 155.00         |
| 11    | –           | Cooling      | Heat Sink (Big)  | 1   | 1,098.00      | 1,098.00       |

**Miscellaneous & Other Costs**
- Miscellaneous (PCB, Bergsticks, Jumper Wires, Breadboard, etc.): **₹125.00**  
- Others: **₹250.00**  
- Engineering Cost (in hours): **200**  

---

## 💰 Cost Estimation
| Item                   | Cost (₹)   |
|-------------------------|------------|
| Components Total        | 2,541.00   |
| Misc + Others           | 375.00     |
| **Subtotal**            | 2,916.00   |
| GST (18%)               | 524.88     |
| **Final Cost**          | 3,440.00   |

---

## 🔌 Circuit Description
- **Arduino Nano**: Main controller unit.  
- **DS18B20 Sensor**: Connected via OneWire on pin A1 for temperature sensing.  
- **LCD (16x2 with I2C)**: Displays seat temperature & cooling status.  
- **Relay Module**: Controls high-power Peltier module ON/OFF.  
- **L298N Motor Driver**: Drives cooling fans (IN1–IN4).  
- **Power Supply**: 7805 voltage regulator provides stable 5V supply.  

---

## 💻 Code Explanation
- Reads temperature from DS18B20.  
- If temperature > 27°C → Relay **ON**, Fans **ON**, LCD shows **Cooling: ON**.  
- If temperature ≤ 27°C → Relay **OFF**, Fans **OFF**, LCD shows **Cooling: OFF**.  
- Updates LCD every 1 second.  

---

## 🚀 How to Run
1. Connect the components as per the circuit diagram.  
2. Upload the code (`Ventilated_Seat.ino`) to Arduino Nano.  
3. Power the system using regulated 5V supply.  
4. Monitor temperature & cooling status on the LCD.  
  

---


## 🔮 Future Improvements
- Add **Bluetooth/Wi-Fi** for wireless monitoring.  
- Allow **adjustable temperature threshold** via buttons or app.  
- Compact **custom PCB design**.  
- Mobile app for **real-time temperature monitoring**.  

---


