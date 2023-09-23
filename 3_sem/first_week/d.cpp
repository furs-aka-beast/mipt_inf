template<typename T, typename U>
T bitCast(U value){
    return *(reinterpret_cast <T*> (&value));
}
int main(){

}