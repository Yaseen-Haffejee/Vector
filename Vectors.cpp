#include <iostream>


using namespace std;

class Vector{
    // Basic functions of a vector are push, pop, indexing , size of the vector and maybe adding and removing from a given index

    private:
    int VectorSize;
    int NumElements = 0;
    // The vector we will be using 
    int * myVector;
    public:
    //Constructor intializing the size of the vector
    Vector(int size){
        myVector = new int[size];
        VectorSize = size;
    }

    //Get the size of the array including empty spaces
    int getVectorSize(){

        return VectorSize;

    }

    //Gets the total number of elements in the vector
    int getNumberOfElements(){

        return NumElements;

    }

    // If the array is full, reallocate double it's size and copy the elements over
    void Reallocate(int size){

        int *  newVector = new int[size];

        for(int i=0; i<VectorSize;i++){
            newVector[i] = myVector[i];
        }
        VectorSize = size;

        delete [] myVector;
        myVector = newVector;

    }


    void Push(int x){

        //Check if the array is full
        if(NumElements == VectorSize){
            Reallocate(VectorSize*2);
        }
        myVector[NumElements] = x;
        NumElements ++;
        
    }

    void Pop(){
    
    try{

        //Check if the array is empty
        if (NumElements == 0 ){
            throw(0);
        }
        else{
            myVector[NumElements-1] = 0;
            NumElements--;
            //Check if array is less than a quarter full and downsize the vector by reallocating to half the space
            if((NumElements/VectorSize)*1.0 <0.25){
                // Half the size of the vector
                Reallocate(VectorSize/2);

            }

        }

    }

    catch(int numElement){
        cout<< "Cannot remove item from an empty array";
    }

    }

    int getElementAtIndex(int index){
        return myVector[index];
    }

    void insertAtIndex(int index, int value){
        
        int * newVector;
        bool passedIndex = false;

        if(NumElements == VectorSize){
            Reallocate(VectorSize*2);
        }
        //If we want to add to the end then it is just a normal push
        if(index == NumElements){
            Push(value);
        }
        else{
            newVector = new int[VectorSize];
            newVector[index] = value;
            for(int i=0;i<NumElements+1;i++){
                if(i==index){
                    passedIndex = true;
                    continue;
                }
                else{
                    if(passedIndex){
                        //We are one pass ahead so access old vector one index behind
                        newVector[i] = myVector[i-1];
                    }
                    else{
                        newVector[i] = myVector[i];
                    }
                }
            }
            delete[] myVector;
            NumElements++;
            myVector = newVector;
        }
    }

    void removeAtIndex(int index){
        NumElements --;
        if(index == 0){
            int * temp = &myVector[1];
            myVector = temp;
        }
        else{
            int * temp = new int[VectorSize];
            bool passedIndex = false;
            for(int i=0;i<NumElements+1;i++){
                if(i == index){
                    passedIndex = true;
                    continue;
                }
                else{
                    if(passedIndex){
                        temp[i-1] = myVector[i];
                    }
                    else{
                    temp[i] = myVector[i];
                    }
                }
            }
            delete[] myVector;
            myVector = temp;
        }
    }

};

int main(){

    int size;
    cout<<"Please enter a number:"<<endl;
    cin >> size;
    
    Vector v = Vector(size);
    
    for(int i=1;i<6;i++){
        v.Push(i);

    }
    cout<<v.getNumberOfElements()<<endl;
    v.removeAtIndex(1);
    for(int i=0;i<v.getNumberOfElements();i++){
        cout<<v.getElementAtIndex(i)<<endl;
    }


    return 0;
}