# Orientation Classification of Accelerometer Data Using the K-Means Algorithm

## Project Participants: Juho Kupila ja Jaakko Lukkari

## Description
In this project, a system ([Figure 1](#kuva1)) is developed that utilizes the nRF5340-DK development board, an accelerometer, a Raspberry Pi, a Linux server, and the K-means algorithm. The nRF5340-DK device transmits accelerometer data from the attached sensor to the Raspberry Pi via a Bluetooth connection. The Raspberry Pi forwards the received data to a MySQL database located on a Linux server. The data received by the database is stored in a `.csv` file, which is then used to develop a Python application utilizing the K-means algorithm to create a neural network.


## Project Objective
<img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/arkkitehtuuritaulu.jpeg" id="figure1" width="600">
<em>Figure 1. System architecture</em>

## Technologies Used in the Project and Skills to Be Learned

### Hardware and Platforms

- **nRF5340-DK**: Measurement of accelerometer (GY-61 ADXL335) ([Figure 2](#figure2)) data, such as acceleration and orientation, and wireless data transmission to the Raspberry Pi using a 433 MHz Bluetooth connection.

  <img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/nRF%20ja%20GY-61.jpg" id="figure2" width="400">
<em>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Figure 2. nRF5340-DK and the attached accelerometer (GY-61)</em>

- **Raspberry Pi 3 Model B v1.2**: Forwards data received from the nRF5340-DK to the school's MySQL server over the network using the HTTP protocol.
- **Laptop computer**: Used for writing code, monitoring the database, and establishing remote connections to the Raspberry Pi and the Linux server.

### Operating Systems and Tools

- **Windows**: Windows 11 and 10.
- **Linux**: Debian-based 32-bit Raspberry Pi OS (latest version).
- **GitHub and Git Bash**: Used for managing the overall project files.

### Programming Languages and Development Environments

- **Visual Studio Code**: Development environment used for writing C and Python code.
- **Google Colab**: Used for writing the neural network classifier code.
- **Python**: Program running on the Raspberry Pi that receives sensor data and stores it in the database. Also used for machine learning–related programs.
- **SQL**: MySQL database used for collecting accelerometer data.
- **C**: Programming language used on the nRF5340-DK to collect accelerometer data and transmit it to the Raspberry Pi via Bluetooth.
- **Linux**: Used on both the Raspberry Pi and the Linux server.

### Database Software

- **MySQL**: A self-created database hosted on one of the Linux server’s addresses.

### Data Analysis and Machine Learning

- **K-means Algorithm**: We use the K-means algorithm ([Figure 3](#figure3)) to cluster the accelerometer x-, y-, and z-axis data into six cluster centers by calculating the distance to the nearest randomly initialized cluster centroid. A new cluster centroid is computed as the mean of the data points assigned to that cluster. The assignment of data points and recalculation of centroids is repeated until no significant changes are observed in the cluster centers.

- **Neural Network Classifier**: Classifies the measurement data into the correct category using two Dense layers by applying the neural network’s weights. The final output consists of probability values for each orientation. This serves as an alternative method for classifying measurement data in addition to the K-means algorithm.


  <img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/k-means.png" id="figure3" width="400">
<em>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Figure 3. Cluster centroids assigned by the K-means algorithm based on the data points</em>

- **Confusion Matrix**: The confusion matrix indicates the performance and effectiveness of the classification algorithm.
- **Wireshark**: An application used to analyze data packets in traffic between devices.

### Version Control and Collaboration

- **Git and GitHub**: Used for managing the project’s file structure and version control.
- **Kanban Board**: Used to track completed and ongoing tasks.
- **Discord**: Used for daily information and file sharing.

### Communication

- **Discord**: A Discord channel created by the teacher, along with separate collaboration channels.
- **Email**:
- Jaakko Lukkari: t3luja00@students.oamk.fi
- Juho Kupila: t3kuju03@students.oamk.fi

![cat](https://github.com/user-attachments/assets/40d21bcd-b78e-4812-a3a4-a9b49c3251da)
