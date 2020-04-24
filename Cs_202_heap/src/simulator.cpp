#include <iostream>
#include <fstream>
#include "maxHeap1.h"

using namespace std;

const int** readData(string fileName, int& itemCount){
    //itemCount;

    ifstream reader;
    reader.open(fileName.c_str());


    reader >> itemCount;
    const int** data = new const int*[itemCount];



    //int i = 0;
    int j = 0;

    while(!reader.eof()){
        int* patient = new int[4];

        for(int i = 0; i < 4; i++){
            reader >> patient[i];
        }

         data[j] = patient;
//        j++;
//
//        if(j % 4 == 0)
            j++;
    }

    return data;

}

double evaluate(const int** data, const int doctorCount, const int patientCount){
    int doctors[doctorCount];
    bool doctorFree[doctorCount];

    bool arrivedPatients[patientCount];
    int arrivalTimes[patientCount];
    int examinationTime[patientCount];
    bool examinedPatients[patientCount];
    bool examiningPatients[patientCount];
    int avgWait = 0;

    for(int i = 0; i < doctorCount; i++){
        doctors[i] = 0;
        doctorFree[i] = true;
    }


    for(int i = 0; i < patientCount; i++){
        arrivedPatients[i] = false;
        examiningPatients[i] = false;
        examinedPatients[i] = false;
        arrivalTimes[i] = -1;
    }

    //int examined[]
    maxHeap1 heap = maxHeap1();
    int currTime = data[0][2];

    bool finished = false;

    do{
   // cout << "Current time: "<< currTime << endl;

    for(int i = 0; i < patientCount; i++){
//        int samePriorityIndex = -1;
//
//        for(int j = i + 1; j < patientCount; j++){
//            if(data[i][1] == data[j][1]){
//                samePriorityIndex = j;
//            }
//        }
//
        if(data[i][2] == currTime && !examinedPatients[i] && !arrivedPatients[i]){
            heap.add(data[i]);
            arrivedPatients[i] = true;
            arrivalTimes[i] = currTime;

           // cout << "Patient " << i + 1 << " arrive at " << currTime << endl;
        }
    }

    //while(!heap.isEmpty()){
//    for(int i = 0; i < doctorCount; i++){
//            if(doctorFree[i] && !heap.isEmpty()){
//                heap.remove(doctors[i]);
//                cout << "Doctor "<< i <<  " takes patient " << doctors[i] << " at time " << currTime<< endl;
//
//                for(int j = 0; j < patientCount; j++){
//                    if(doctors[i] == data[j][0]){
//                        examiningPatients[j] = true;
//                        examinationTime[j] = currTime;
//                        doctorFree[i] = false;
//                    }
//                }
//
//            }
//       }
//       for(int i = 0; i < doctorCount; i++){
//            if(doctorFree[i] && !heap.isEmpty()){
//                int patient1;
//                int patient2;
//
//                heap.remove(patient1);
//                heap.remove(patient2);
//
//                for(int index = 0; index < patientCount; index++){
//                    if(data[index][0] == patient1){patient1 = index;break;}
//                    //if(data[index][0] == patient2){patient2 = index;}
//                }
//                for(int index = 0; index < patientCount; index++){
//                    //if(data[index][0] == patient1){patient1 = index;}
//                    if(data[index][0] == patient2){patient2 = index;break;}
//                }
//
//                int chosenPatient = 0;
//
//                if(data[patient1][1] == data[patient2][1]){
//                    if(arrivedPatients[patient1] && arrivedPatients[patient2] ){
//                        if(arrivalTimes[patient1] >= arrivalTimes[patient2]){
//                            chosenPatient = patient2;
//                            heap.add(data[patient1]);
//                        }else{
//                            chosenPatient = patient1;
//                            heap.add(data[patient2]);
//                        }
//                    }else{
//                        chosenPatient = patient1;
//                        heap.add(data[patient2]);
//                    }
//                }else{
//                    chosenPatient = patient1;
//                    heap.add(data[patient2]);
//                }
//
//                doctors[i] = data[chosenPatient][0];
//                cout << "Doctor "<< i <<  " takes patient " << doctors[i] << " at time " << currTime<< endl;
//
//                for(int j = 0; j < patientCount; j++){
//                    if(doctors[i] == data[j][0]){
//                        examiningPatients[j] = true;
//                        examinationTime[j] = currTime;
//                        doctorFree[i] = false;
//                    }
//                }
//
//            }
//       }


for(int i = 0; i < doctorCount; i++){
            if(doctorFree[i] && !heap.isEmpty()){
                int patient1;
                int patient2;

                heap.remove(patient1);


                if(!heap.isEmpty()){
                heap.remove(patient2);
                int chosenPatient = 0;
                for(int index = 0; index < patientCount; index++){
                    if(data[index][0] == patient1){patient1 = index;break;}
                    //if(data[index][0] == patient2){patient2 = index;}
                }
                for(int index = 0; index < patientCount; index++){
                    //if(data[index][0] == patient1){patient1 = index;}
                    if(data[index][0] == patient2){patient2 = index;break;}
                }



                if(data[patient1][1] == data[patient2][1]){
                    if(arrivedPatients[patient1] && arrivedPatients[patient2] ){
                        if(data[patient1][2] >= data[patient2][2]){
                            chosenPatient = patient2;
                            heap.add(data[patient1]);
                        }else{
                            chosenPatient = patient1;
                            heap.add(data[patient2]);
                        }
                    }else{
                        chosenPatient = patient1;
                        heap.add(data[patient2]);
                    }
                }else{
                    chosenPatient = patient1;
                    heap.add(data[patient2]);
                }

                doctors[i] = data[chosenPatient][0];
                }else{
                    doctors[i] = patient1;
                }


                cout << "Doctor "<< i <<  " takes patient " << doctors[i] << " at time " << currTime<< endl;

                for(int j = 0; j < patientCount; j++){
                    if(doctors[i] == data[j][0]){
                        examiningPatients[j] = true;
                        examinationTime[j] = currTime;
                        doctorFree[i] = false;
                    }
                }

            }
       }

   // cout << "before time: " << currTime << endl;
//    int minExam = 0;
//    for(int i = 0; i < doctorCount; i++){
//            //if(true){}
//
//
//        for(int j = 0; j < patientCount; j++){
//            if(data[j][0] == doctors[i]){
//                if(data[j][3] <= minExam){
//                    minExam = data[j][3];
//                }
//
//                if(i == 0){
//                    minExam = data[j][3];
//                    //j = 0;
//                }
//             }
//         }
//       }
//
//        cout << "min time: " << minExam << endl;
//       currTime += minExam;

       for(int i = 0; i < patientCount; i++){
            if(examiningPatients[i]){//!examinedPatients[i] && arrivedPatients[i]){
                if(currTime - examinationTime[i] == data[i][3]){
                    //cout <<"Patient "<< data[i][0]  << " is examied"<<endl;
                    examinedPatients[i] = true;
                    examiningPatients[i] = false;

                    for(int j = 0; j < doctorCount; j++){
                        if(doctors[j] == data[i][0]){
                            doctorFree[j] = true;
                            //cout << "Doctor " << j << " free" << endl;
                        }
                    }

                }
            }
       }

//    for(int i = 0; i < doctorCount; i++){
//        if(doctorFree[i] && !heap.isEmpty()){
//            heap.remove(doctors[i]);
//            cout << "Doctor "<< i <<  " takes patient " << doctors[i] << " at time " << currTime<< endl;
//
//            for(int j = 0; j < patientCount; j++){
//                if(doctors[i] == data[j][0] ){
//                    examiningPatients[j] = true;
//                    examinationTime[j] = currTime;
//                    doctorFree[i] = false;
//                }
//            }
//        }
//    }

for(int i = 0; i < doctorCount; i++){
            if(doctorFree[i] && !heap.isEmpty()){
                int patient1;
                int patient2;

                heap.remove(patient1);
                int chosenPatient = 0;

                if(!heap.isEmpty()){
                heap.remove(patient2);

                for(int index = 0; index < patientCount; index++){
                    if(data[index][0] == patient1){patient1 = index;break;}
                    //if(data[index][0] == patient2){patient2 = index;}
                }
                for(int index = 0; index < patientCount; index++){
                    //if(data[index][0] == patient1){patient1 = index;}
                    if(data[index][0] == patient2){patient2 = index;break;}
                }



                if(data[patient1][1] == data[patient2][1]){
                    //if(arrivedPatients[patient1] && arrivedPatients[patient2] ){
                        if(data[patient1][2] >= data[patient2][2]){
                            chosenPatient = patient2;
                            heap.add(data[patient1]);
                        }else{
                            chosenPatient = patient1;
                            heap.add(data[patient2]);
                        }
//                    }else{
//                        chosenPatient = patient1;
//                        heap.add(data[patient2]);
//                    }
                }else{
                    chosenPatient = patient1;
                    heap.add(data[patient2]);
                }
                doctors[i] = data[chosenPatient][0];
                }else{
                    doctors[i] = patient1;
                }


                cout << "Doctor "<< i <<  " takes patient " << doctors[i] << " at time " << currTime<< endl;

                for(int j = 0; j < patientCount; j++){
                    if(doctors[i] == data[j][0]){
                        examiningPatients[j] = true;
                        examinationTime[j] = currTime;
                        doctorFree[i] = false;
                    }
                }

            }
       }


    currTime++;



    for(int i = 0; i < patientCount; i++){
        if(examinedPatients[i]){
            finished = true;
        }else{
            finished = false;
            break;
        }
    }

    //int avgWait = 0;
    if(finished){
        for(int i = 0; i < patientCount; i++){
            cout <<"Patient " << i + 1 << " waited "<< examinationTime[i] - arrivalTimes[i]<< "minutes" << endl;
            avgWait += (examinationTime[i] - arrivalTimes[i]);
        }

    }
    }while(!finished);
    //}
    //for(int i = 0; i < patientCount; i++)
        //heap.add(data[i]);
//    for(int i = 0; i < doctorCount; i++){
//        if(!heap.isEmpty()){
//            heap.remove();
//        }
//    }
   // heap.print();
    return (double)avgWait / (double)patientCount;

//    for(int time = 0; ;time++){
//        for(int i = 0; i < patientCount; i++){
//            if(time == data[i][2]){
//                heap.add(data[i]);
//            }
//        }

    //}
}

int main(int argc, char * argv[])
{
    //std::cout << "Hello, World!" << std::endl;

    string fileName = "E:\\Cs 202 hws\\Heap hw\\C-Heap-Homework\\Cs_202_heap\\src\\data.txt";//(string)argv[1];
    int averageWait = 10;//(int)argv[2];

    int patientCount = 0;
    const int** data = readData(fileName, patientCount);;




    //int priority [patientCount];

    for(int i = 0; i < patientCount; i++){
        for(int j = 0; j < 4; j++)
           cout << " " << data[i][j];
       // priority[i] = data[i][1];

            cout << endl;
    }


    //bool examined[itemCount];

    int optimalDoctorCount = 0;
    double wait = 0.0;

    for(int doctorCount = 1; doctorCount <= patientCount; doctorCount++){
        wait = evaluate(data,doctorCount,12);
        //cout << "average wait: " << wait << endl;
        if(wait <= averageWait){
            optimalDoctorCount = doctorCount;
            break;
        }
    }

    cout << "Optimal doctor count: " << optimalDoctorCount << endl;
    cout << "Average wait: " << wait << endl;


    //heap.add(6);
//    heap.print();

    //cout << heap.isEmpty() << endl;
    //cout << heap.getHeight() << endl;
    //cout << heap.getNumberOfNodes() << endl;
    //heap.add(3);
    //cout << "---------------------------------------------------" << endl;
    //heap.print();
    //cout << heap.isEmpty() << endl;
    //heap.add(6);
    //cout << heap.isEmpty() << endl;
    //heap.add(15);
    //heap.add(17);
    //cout << "---------------------------------------------------" << endl;
    //heap.print();

    //heap.add()

//    heap.print();
    //heap.remove();
    //heap.print();
//    cout << "Height: " << heap.getNumberOfNodes() << endl;

//    maxHeap1 heap = maxHeap1();
//    //int currTime = data[0][2];
//
////    for(int i = 0; i < patientCount; i++){
////        if(data[i][2] == currTime){
////            heap.add(data[i]);
////        }
////    }
//    for(int i = 0; i < patientCount; i++)
//        heap.add(data[i]);
//
//    heap.remove();
//    cout << heap.getHeight()<<endl;
//    cout << heap.getNumberOfNodes()<<endl;
//    //cout << heap.<<endl;
//    //cout << heap.<<endl;
//
//        heap.print();
    return 0;
}
