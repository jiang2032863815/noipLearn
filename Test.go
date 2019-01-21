package main
import (
	"fmt"
	"os"
)
func main(){
	var bs=make([]byte,10)
	for{
		if n,err:=os.Stdin.Read(bs);err==nil{
			fmt.Println(n)
			fmt.Println(bs)
		}
	}
}