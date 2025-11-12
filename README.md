# 🖐️ IoT-Based Smart Glove Mouse using ESP32

A wearable, gesture-controlled Bluetooth mouse built using the **ESP32**, **MPU6050**, and **SS49E Hall sensors**.  
This project transforms hand movements and magnetic gestures into real-time mouse actions such as cursor movement, left/right clicks, and activation control — all without a physical mouse!

---

## 🚀 Features

- 🎮 **Motion-based cursor control** using MPU6050 (accelerometer + gyroscope)
- 🧲 **Magnet-based click detection** using SS49E Hall sensors
- 🔋 **Battery-powered & rechargeable** (3.7 V Li-ion + TP4056 + AMS1117 3.3 V)
- 📶 **Wireless Bluetooth HID** connection to any laptop or PC
- 🧤 **Wearable glove design** for intuitive, touch-free human–computer interaction
- ⚙️ **Fully programmable** using Arduino IDE

---

## 🧩 Components Used

| Component | Function |
|------------|-----------|
| **ESP32 (NodeMCU-32 / WROVER-E)** | Main microcontroller with Bluetooth HID support |
| **MPU6050** | Detects hand tilt for cursor movement |
| **SS49E Hall Sensors (x3)** | Detects magnet proximity for left/right click and movement activation |
| **Li-ion 3.7 V 450 mAh Battery** | Portable power source |
| **TP4056 Charger Module** | Safely charges the Li-ion cell |
| **AMS1117-3.3 V Regulator** | Provides stable 3.3 V for ESP32 & sensors |
| **Slide Switch** | Power control |

---

## 🔌 Circuit Overview

Battery (3.7 V) → TP4056 → AMS1117 → ESP32 (3.3 V)
↘ Sensors (VCC = 3.3 V, GND = GND)
MPU6050: SDA → GPIO21 | SCL → GPIO22
SS49E: OUT → GPIO34 (Move)
OUT → GPIO35 (Left Click)
OUT → GPIO32 (Right Click)


---

## 💻 Software Details

- **Platform:** Arduino IDE 2.x  
- **Board:** ESP32 Dev Module / NodeMCU-32S  
- **Libraries Required:**
  - `ESP32 BLE Mouse` by T-vK  
  - `MPU6050_light` by ricki-z  
  - `Wire` (built-in)

---

## 🧠 Working Principle

1. **Tilt Detection:**  
   MPU6050 reads hand tilt angles → mapped to X/Y cursor motion.  

2. **Click Detection:**  
   SS49E sensors detect magnet proximity → trigger left/right mouse click.  

3. **Movement Enable:**  
   A third SS49E toggles motion mode on/off.  

4. **Bluetooth Communication:**  
   ESP32 sends HID signals wirelessly → laptop interprets as standard mouse input.  

---

## 🧪 Results

- ✅ Smooth and responsive cursor control  
- ✅ Left/Right click accuracy > 95%  
- ✅ Bluetooth latency < 100 ms  
- ✅ Battery runtime ≈ 2 hours continuous use  

---

## 📸 Project Preview

https://github.com/rizwanmallick/Smart-Glove-Hand-Gesture-Mouse/blob/main/smart%20glove.jpg

---

## 🧰 Future Improvements

- Add **finger tracking** for scroll and gesture input  
- Implement **power-saving** modes  
- Include **Wi-Fi remote control** for presentations  
- Upgrade to **flex sensor**-based finger detection  

---

## 🧑‍💻 Author

**Rizwan Mallick**  
B.Tech ECE | IoT & Embedded Systems Enthusiast  
🔗 [LinkedIn](https://www.linkedin.com/public-profile/settings?trk=d_flagship3_profile_self_view_public_profile&lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base%3BqV0Bz9fDSSSudFR8AET31A%3D%3D) | 🌐 [GitHub](https://github.com/rizwanmallick)

---

## 🪪 License

This project is open-source under the **MIT License**.  
Feel free to use, modify, and share with proper credits.
