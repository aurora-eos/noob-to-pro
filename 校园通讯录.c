/*校园通讯录
时间限制
512 ms
内存限制
64 MB
总分
100
￼
校园通讯录支持添加、查询和删除联系人。
￼
第一行输入初始联系人数量 n 和后续操作的数量 q
随后输入 n 行“姓名 电话”
再输入 q 个操作：1 姓名 电话（添加或覆盖），2 姓名（查询），3 姓名（删除）。
￼
对每个查询操作输出电话
不存在输出Not Found*/
#include<stdio.h>
#include<string.h>
int main(void){
    struct Contect{
        char name[100];
        char num[100];
    };
    
    int n,q;
    scanf("%d %d",&n,&q);
    int count=n;
    struct Contect a[n+q+1];
    for(int i=0;i<n;i++){
       scanf("%99s %99s",a[i].name,a[i].num);
    }
    for(int i=0;i<q;i++){
        int op;
        char name[100];
        scanf("%d %99s",&op,name);
        int pos=-1;
        for(int j=0;j<count;j++){
            
            if(strcmp(a[j].name,name)==0){
                pos=j;
                break;
            }
        }
        if(op==1){
            if(pos==-1){
                pos=count;
                strcpy(a[pos].name,name);
                count++;
            }
            scanf("%99s",a[pos].num);
        }
        
        else if(op==2){
            if(pos==-1){
            printf("Not Found\n");
            }else{
                printf("%s\n",a[pos].num);
            }
        }
        else if(op==3){
            if(pos!=-1){
                a[pos]=a[count-1];
                count--;
            }
        }
    }
    return 0;


}
