#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct profileNode    // Profile Linked List
{
    char name[100];
    char BusCpName[100];
    char NameOfRoot[100];
    int position;
    struct profileNode *next;
};

struct nodeBus // Bus Company
{
    char nameB[100];
    struct nodeBus *link;
};

struct RootOfBus1  // Route of Bus-> SHYAMOLI
{
    char nameOfroot[100];
    struct RootOfBus1 *link1;
};

struct seatNode  // Seats of First Bus -> SHYAMOLI
{
    int seatNum;
    struct seatNode *link2;
};

struct seatNode1   // Seats of Second Bus -> SHYAMOLI
{
    int seatNum1;
    struct seatNode1 *link3;
};

struct RootOfBus2  // Route of Bus-> HANIF
{
    char nameOfroot1[100];
    struct RootOfBus2 *link1B;
};

struct seatNodeB    // Seats of First Bus-> HANIF
{
    int seatNumB;
    struct seatNodeB *link2B;
};

struct seatNodeB1  // Seats of Second Bus -> HANIF
{
    int seatNumB1;
    struct seatNodeB1 *link3B;
};

struct RootOfBus3 // Route of Bus -> ENA
{
    char nameOfroot2[100];
    struct RootOfBus3 *link1C;
};

struct seatNodeC // Seats of First Bus -> ENA
{
    int seatNumC;
    struct seatNodeC *link2C;
};

struct seatNodeC1 //Seats of Second Bus -> ENA
{
    int seatNumC1;
    struct seatNodeC1 *link3C;
};

struct profileNode *mainHead;

struct RootOfBus1 *headS;

struct nodeBus *head;

struct seatNode *headSeat;

struct seatNode1 *headSeat1;

struct RootOfBus2 *headH;

struct seatNodeB *headseatB;

struct seatNodeB1 *headseatB1;

struct RootOfBus3 *headE;

struct seatNodeC *headseatC;

struct seatNodeC1 *headseatC1;

int IdentifierOfBus;    // For Identifying The Route of Buses

void Display()  // Display of BUS Company name
{
    int i=1;
    struct nodeBus *temp = head;
    printf("\n");
    while(temp != NULL)
    {
        printf("\t\t\t\t\t[%d] => %s\n\n", i, temp->nameB);
        i++;
        temp = temp->link;
    }
}

void DisplayStatus()    // Display of Profile Information
{
    int i=1;
    if(mainHead == NULL)
    {
        printf("\n\n\t\t\t\t\tYou haven't booked any tickets yet!!!");
    }
    else
    {
        struct profileNode *temp = mainHead;
        while(temp != NULL)
        {
            printf("\n\n\t\t\t\t\tTicket number %d:\n\n", i);
            printf("\t\t\t\t\tName of the ticket holder: %s\n\n", temp->name);
            printf("\t\t\t\t\tName of the bus company: %s\n\n", temp->BusCpName);
            printf("\t\t\t\t\tRoute of the bus: %s\n\n", temp->NameOfRoot);
            printf("\t\t\t\t\tPosition of the ticket: %d\n\n", temp->position);

            i++;
            temp = temp->next;
        }
    }
}

void InsertCancelledTicket(char companyN[], char RouteN[], int TPosition)
{
    int i=1, count;
    struct nodeBus *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->nameB, companyN)==0)
        {
            count = i;
        }
        i++;
        temp = temp->link;
    }
    if(count == 1)
    {
        int j=1, count1;
        struct RootOfBus1 *ptr = headS;
        while(ptr != NULL)
        {
            if(strcmp(ptr->nameOfroot, RouteN)==0)
            {
                count1 = j;
            }
            j++;
            ptr = ptr->link1;
        }
        if(count1 == 1)
        {
            int k=1, count2;
            struct seatNode *pt = headSeat;
            while(pt != NULL)
            {
                if(pt->seatNum > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link2;
            }

            struct seatNode *pt2 = headSeat;

            struct seatNode *ptr2 = (struct seatNode *)malloc(sizeof(struct seatNode));
            ptr2->seatNum=TPosition;
            ptr2->link2=NULL;

            if(count2 == 1)
            {
                ptr2->link2 = headSeat;
                headSeat = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link2;
                }
                ptr2->link2=pt2->link2;
                pt2->link2=ptr2;
            }
        }
        else if(count1 == 2)
        {
            int k=1, count2;
            struct seatNode1 *pt = headSeat1;
            while(pt != NULL)
            {
                if(pt->seatNum1 > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link3;
            }

            struct seatNode1 *pt2 = headSeat1;

            struct seatNode1 *ptr2 = (struct seatNode1 *)malloc(sizeof(struct seatNode1));
            ptr2->seatNum1=TPosition;
            ptr2->link3=NULL;

            if(count2 == 1)
            {
                ptr2->link3 = headSeat1;
                headSeat1 = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link3;
                }
                ptr2->link3=pt2->link3;
                pt2->link3=ptr2;
            }
        }
    }
    else if(count == 2)
    {
        int j=1, count1;
        struct RootOfBus2 *ptr = headH;
        while(ptr != NULL)
        {
            if(strcmp(ptr->nameOfroot1, RouteN)==0)
            {
                count1 = j;
            }
            j++;
            ptr = ptr->link1B;
        }
        if(count1 == 1)
        {
            int k=1, count2;
            struct seatNodeB *pt = headseatB;
            while(pt != NULL)
            {
                if(pt->seatNumB > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link2B;
            }

            struct seatNodeB *pt2 = headseatB;

            struct seatNodeB *ptr2 = (struct seatNodeB *)malloc(sizeof(struct seatNodeB));
            ptr2->seatNumB=TPosition;
            ptr2->link2B=NULL;

            if(count2 == 1)
            {
                ptr2->link2B = headseatB;
                headseatB = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link2B;
                }
                ptr2->link2B=pt2->link2B;
                pt2->link2B=ptr2;
            }
        }
        else if(count1 == 2)
        {
            int k=1, count2;
            struct seatNodeB1 *pt = headseatB1;
            while(pt != NULL)
            {
                if(pt->seatNumB1 > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link3B;
            }

            struct seatNodeB1 *pt2 = headseatB1;

            struct seatNodeB1 *ptr2 = (struct seatNodeB1 *)malloc(sizeof(struct seatNodeB1));
            ptr2->seatNumB1=TPosition;
            ptr2->link3B=NULL;

            if(count2 == 1)
            {
                ptr2->link3B = headseatB1;
                headseatB1 = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link3B;
                }
                ptr2->link3B=pt2->link3B;
                pt2->link3B=ptr2;
            }
        }
    }
    else if(count == 3)
    {
        int j=1, count1;
        struct RootOfBus3 *ptr = headE;
        while(ptr != NULL)
        {
            if(strcmp(ptr->nameOfroot2, RouteN)==0)
            {
                count1 = j;
            }
            j++;
            ptr = ptr->link1C;
        }
        if(count1 == 1)
        {
            int k=1, count2;
            struct seatNodeC *pt = headseatC;
            while(pt != NULL)
            {
                if(pt->seatNumC > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link2C;
            }

            struct seatNodeC *pt2 = headseatC;

            struct seatNodeC *ptr2 = (struct seatNodeC *)malloc(sizeof(struct seatNodeC));
            ptr2->seatNumC=TPosition;
            ptr2->link2C=NULL;

            if(count2 == 1)
            {
                ptr2->link2C = headseatC;
                headseatC = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link2C;
                }
                ptr2->link2C=pt2->link2C;
                pt2->link2C=ptr2;

            }
        }
        else if(count1 == 2)
        {
            int k=1, count2;
            struct seatNodeC1 *pt = headseatC1;
            while(pt != NULL)
            {
                if(pt->seatNumC1 > TPosition)
                {
                    count2 = k;
                    break;
                }
                k++;
                pt = pt->link3C;
            }

            struct seatNodeC1 *pt2 = headseatC1;

            struct seatNodeC1 *ptr2 = (struct seatNodeC1 *)malloc(sizeof(struct seatNodeC1));
            ptr2->seatNumC1=TPosition;
            ptr2->link3C=NULL;

            if(count2 == 1)
            {
                ptr2->link3C = headseatC1;
                headseatC1 = ptr2;
            }
            else
            {
                for(i=1; i<(count2-1); i++)
                {
                    pt2=pt2->link3C;
                }
                ptr2->link3C=pt2->link3C;
                pt2->link3C=ptr2;
            }
        }
    }
}

void CancelTicket()
{
    int i=1, Common, TPosition;
    char companyN[100], RouteN[100];

    if(mainHead == NULL)
    {
        printf("\n\n\t\t\t\t\tYou haven't booked any tickets yet!!!");
    }
    else
    {
        DisplayStatus();
        printf("\n\n\t\t\t\tEnter the ticket number which you want to cancel: ");
        scanf("%d", &Common);

        struct profileNode *pt = mainHead, *pt1 = mainHead;
        if(Common == 1)
        {
            strcpy(companyN, pt1->BusCpName);
            strcpy(RouteN, pt1->NameOfRoot);
            TPosition = pt1->position;

            mainHead = pt1->next;
            free(pt1);
            pt1 = NULL;
        }
        else
        {
            for(i=0; i<Common-1; i++)
            {
                pt = pt1;
                pt1 = pt1->next;
            }
            pt->next = pt1->next;

            strcpy(companyN, pt1->BusCpName);
            strcpy(RouteN, pt1->NameOfRoot);
            TPosition = pt1->position;

            free(pt1);
            pt1 = NULL;
        }
        printf("\n\n\t\t\t\tYour ticket has been successfully cancelled!!!");

        InsertCancelledTicket(companyN, RouteN, TPosition);
    }

}

void ReserveTicket(char NameOfcP[], char nameOfRoot[], int tCnumS, int rootChoice)
{
    int TcPos[32], n=0, i;
    for(i=0; i<tCnumS; i++)
    {
        printf("\n\t\t%d.Position of the seat: ", i+1);
        scanf("%d", &TcPos[i]);
    }

    if(mainHead != NULL)
    {
        struct profileNode *pt = mainHead, *s2, *s1;
        while(pt->next != NULL)
        {
            pt = pt->next;
        }

        s2 = (struct profileNode *)malloc(sizeof(struct profileNode));
        printf("\n\n\t\tEnter the name of the ticket holder for seat number %d: ", TcPos[n]);
        scanf("%s", s2->name);
        strcpy(s2->BusCpName, NameOfcP);
        strcpy(s2->NameOfRoot, nameOfRoot);
        s2->position = TcPos[n];
        s2->next = NULL;

        pt->next = s2;
        s1 = s2;
        for(n=1; n<tCnumS; n++)
        {
            s2 = (struct profileNode *)malloc(sizeof(struct profileNode));
            printf("\n\n\t\tEnter the name of the ticket holder for seat number %d: ", TcPos[n]);
            scanf("%s", s2->name);
            strcpy(s2->BusCpName, NameOfcP);
            strcpy(s2->NameOfRoot, nameOfRoot);
            s2->position = TcPos[n];
            s2->next = NULL;

            s1->next = s2;
            s1 = s1->next;
        }

    }
    else
    {
        struct profileNode *s1, *s2;
        s2 = (struct profileNode *)malloc(sizeof(struct profileNode));
        printf("\n\n\t\tEnter the name of the ticket holder for seat number %d: ", TcPos[n]);
        scanf("%s", s2->name);
        strcpy(s2->BusCpName, NameOfcP);
        strcpy(s2->NameOfRoot, nameOfRoot);
        s2->position = TcPos[n];
        s2->next = NULL;

        mainHead = s2;
        s1 = mainHead;

        for(n=1; n<tCnumS; n++)
        {
            s2 = (struct profileNode *)malloc(sizeof(struct profileNode));
            printf("\n\n\t\tEnter the name of the ticket holder for seat number %d: ", TcPos[n]);
            scanf("%s", s2->name);
            strcpy(s2->BusCpName, NameOfcP);
            strcpy(s2->NameOfRoot, nameOfRoot);
            s2->position = TcPos[n];
            s2->next = NULL;

            s1->next = s2;
            s1 = s1->next;
        }
    }
    if(tCnumS == 1)
    {
        printf("\n\n\t\t\t\t\tYou have successfully booked %d ticket!!!", tCnumS);
    }
    else
    {
        printf("\n\n\t\t\t\t\tYou have successfully booked %d tickets!!!", tCnumS);
    }

    int CpCount, q=1;
    struct nodeBus *counter = head;
    while(counter != NULL)
    {
        if(strcmp(NameOfcP, counter->nameB) == 0)
        {
            CpCount = q;
        }
        q++;
        counter = counter->link;
    }

    if(CpCount == 1)
    {
        for(i=0; i<tCnumS; i++)
        {
            if(rootChoice == 1)
            {
                int count = 1, position1;
                struct seatNode *ptr = headSeat;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNum)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link2;
                }

                struct seatNode *temp = headSeat;
                if(position1 == 1)
                {
                    headSeat = temp->link2;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link2;
                    }
                    struct seatNode *common = temp->link2;
                    temp->link2 = common->link2;
                    free(common);
                    common = NULL;
                }
            }
            else if(rootChoice == 2)
            {
                int count = 1, position1;
                struct seatNode1 *ptr = headSeat1;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNum1)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link3;
                }

                struct seatNode1 *temp = headSeat1;
                if(position1 == 1)
                {
                    headSeat1 = temp->link3;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link3;
                    }
                    struct seatNode1 *common = temp->link3;
                    temp->link3 = common->link3;
                    free(common);
                    common = NULL;
                }
            }
        }
    }
    else if(CpCount == 2)
    {
        for(i=0; i<tCnumS; i++)
        {
            if(rootChoice == 1)
            {
                int count = 1, position1;
                struct seatNodeB *ptr = headseatB;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNumB)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link2B;
                }

                struct seatNodeB *temp = headseatB;
                if(position1 == 1)
                {
                    headseatB = temp->link2B;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link2B;
                    }
                    struct seatNodeB *common = temp->link2B;
                    temp->link2B = common->link2B;
                    free(common);
                    common = NULL;
                }
            }

            else if(rootChoice == 2)
            {
                int count = 1, position1;
                struct seatNodeB1 *ptr = headseatB1;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNumB1)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link3B;
                }

                struct seatNodeB1 *temp = headseatB1;
                if(position1 == 1)
                {
                    headseatB1 = temp->link3B;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link3B;
                    }
                    struct seatNodeB1 *common = temp->link3B;
                    temp->link3B = common->link3B;
                    free(common);
                    common = NULL;
                }
            }
        }
    }
    else if(CpCount == 3)
    {
        for(i=0; i<tCnumS; i++)
        {
            if(rootChoice == 1)
            {
                int count = 1, position1;
                struct seatNodeC *ptr = headseatC;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNumC)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link2C;
                }

                struct seatNodeC *temp = headseatC;
                if(position1 == 1)
                {
                    headseatC = temp->link2C;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link2C;
                    }
                    struct seatNodeC *common = temp->link2C;
                    temp->link2C = common->link2C;
                    free(common);
                    common = NULL;
                }
            }

            else if(rootChoice == 2)
            {
                int count = 1, position1;
                struct seatNodeC1 *ptr = headseatC1;
                while(ptr != NULL)
                {
                    if(TcPos[i] == ptr->seatNumC1)
                    {
                        position1 = count;
                    }
                    count++;
                    ptr = ptr->link3C;
                }

                struct seatNodeC1 *temp = headseatC1;
                if(position1 == 1)
                {
                    headseatC1 = temp->link3C;
                    free(temp);
                    temp = NULL;
                }
                else
                {
                    for(int i=1; i<position1-1; i++)
                    {
                        temp = temp->link3C;
                    }
                    struct seatNodeC1 *common = temp->link3C;
                    temp->link3C = common->link3C;
                    free(common);
                    common = NULL;
                }
            }
        }
    }

}

void Smdisplay(int N)   // Display of SHYAMOLI
{
    printf("\n\n\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t||                         ||\n");
    printf("\t\t\t\t\t  =*=SHYAMOLI PARIBAHAN=*=  \n");
    printf("\t\t\t\t\t||                         ||\n");
    printf("\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    int choice1, i=1;
    struct RootOfBus1 *temp = headS;
    while(temp != NULL)
    {
        printf("\t\t\t\t\t[%d] => %s\n\n", i, temp->nameOfroot);
        i++;
        temp = temp->link1;
    }

    if(N == 1)
    {
        printf("\n\t\tEnter the bus number in which you want to book a ticket: ");
    }
    else if(N == 2)
    {
        printf("\n\t\tEnter the bus number which bus's seats you want to see: ");
    }
    scanf("%d", &choice1);

    printf("\n\n\t\t\t\t\tAvailable seats of the chosen bus:\n\n");

    if(choice1 == 1)
    {
        struct seatNode *temp1 = headSeat;
        int j=1;
        while(temp1 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp1->seatNum);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp1 = temp1->link2;
            j++;
        }
    }
    if(choice1 == 2)
    {
        struct seatNode1 *temp2 = headSeat1;
        int j=1;
        while(temp2 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp2->seatNum1);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp2 = temp2->link3;
            j++;
        }
    }
    IdentifierOfBus = choice1;
}

void Hfdisplay(int N)   //Display of HANIF
{
    printf("\n\n\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\t\t\t\t\t||                       ||\n");
    printf("\t\t\t\t\t  =*= HANIF PARIBAHAN =*=  \n");
    printf("\t\t\t\t\t||                       ||\n");
    printf("\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

    int choice1, i=1;
    struct RootOfBus2 *temp = headH;
    while(temp != NULL)
    {
        printf("\t\t\t\t\t[%d] => %s\n\n", i, temp->nameOfroot1);
        i++;
        temp = temp->link1B;
    }
    if(N == 1)
    {
        printf("\n\t\tEnter the bus number in which you want to book a ticket: ");
    }
    else if(N == 2)
    {
        printf("\n\t\tEnter the bus number which bus's seats you want to see: ");
    }
    scanf("%d", &choice1);

    printf("\n\n\t\t\t\t\tAvailable seats of the chosen bus:\n\n");

    if(choice1 == 1)
    {
        struct seatNodeB *temp1 = headseatB;
        int j=1;
        while(temp1 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp1->seatNumB);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp1 = temp1->link2B;
            j++;
        }
    }

    if(choice1 == 2)
    {
        struct seatNodeB1 *temp2 = headseatB1;
        int j=1;
        while(temp2 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp2->seatNumB1);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp2 = temp2->link3B;
            j++;
        }
    }

    IdentifierOfBus = choice1;
}

void Enadisplay(int N)  //Display of ENA
{
    printf("\n\n\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t||                       ||\n");
    printf("\t\t\t\t\t  =*=*= ENA TRAVELS =*=*=  \n");
    printf("\t\t\t\t\t||                       ||\n");
    printf("\t\t\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    int choice1, i=1;
    struct RootOfBus3 *temp = headE;
    while(temp != NULL)
    {
        printf("\t\t\t\t\t[%d] => %s\n\n", i, temp->nameOfroot2);
        i++;
        temp = temp->link1C;
    }

    if(N == 1)
    {
        printf("\n\t\tEnter the bus number in which you want to book a ticket: ");
    }
    else if(N == 2)
    {
        printf("\n\t\tEnter the bus number which bus's seats you want to see: ");
    }
    scanf("%d", &choice1);

    printf("\n\n\t\t\t\t\tAvailable seats of the chosen bus:\n\n");

    if(choice1 == 1)
    {
        struct seatNodeC *temp1 = headseatC;
        int j=1;
        while(temp1 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp1->seatNumC);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp1 = temp1->link2C;
            j++;
        }
    }

    if(choice1 == 2)
    {
        struct seatNodeC1 *temp2 = headseatC1;
        int j=1;
        while(temp2 != NULL)
        {
            if(j == 1)
            {
                printf("\t\t");
            }
            printf("%d\t", temp2->seatNumC1);
            if(j%10 == 0)
            {
                printf("\n\n\t\t");
            }
            temp2 = temp2->link3C;
            j++;
        }
    }

    IdentifierOfBus = choice1;
}

void Booking()
{
    int choice, choice1, i=1;           //choice -> Identifying Bus Company!
    printf("\n\n\t\tEnter the bus company number in which you want to book ticket: ");
    scanf("%d", &choice);
    printf("\n");
    if(choice == 1)
    {
        Smdisplay(1);

        int TcNums, k, l, RootChoice = IdentifierOfBus;

        struct RootOfBus1 *temp1 = headS;
        for(l=0; l<RootChoice-1; l++)
        {
            temp1 = temp1->link1;
        }

        struct nodeBus *temp = head;
        for(l=0; l<choice-1; l++)
        {
            temp = temp->link;
        }

        printf("\n\n\t\tThe number of tickets you want to book: ");
        scanf("%d", &TcNums);

        ReserveTicket(temp->nameB, temp1->nameOfroot, TcNums, RootChoice);
    }
    else if(choice == 2)
    {
        Hfdisplay(1);

        int TcNums, k, l, RootChoice = IdentifierOfBus;

        struct RootOfBus2 *temp1 = headH;
        for(l=0; l<RootChoice-1; l++)
        {
            temp1 = temp1->link1B;
        }

        struct nodeBus *temp = head;
        for(l=0; l<choice-1; l++)
        {
            temp = temp->link;
        }

        printf("\n\n\t\tThe number of tickets you want to book: ");
        scanf("%d", &TcNums);

        ReserveTicket(temp->nameB, temp1->nameOfroot1, TcNums, RootChoice);

    }
    else if(choice == 3)
    {
        Enadisplay(1);

        int TcNums, k, l, RootChoice = IdentifierOfBus;

        struct RootOfBus3 *temp1 = headE;
        for(l=0; l<RootChoice-1; l++)
        {
            temp1 = temp1->link1C;
        }

        struct nodeBus *temp = head;
        for(l=0; l<choice-1; l++)
        {
            temp = temp->link;
        }

        printf("\n\n\t\tThe number of tickets you want to book: ");
        scanf("%d", &TcNums);

        ReserveTicket(temp->nameB, temp1->nameOfroot2, TcNums, RootChoice);

    }

}

void DeleteEditedPosition(int CpCount, int rootChoice, int TcPos)
{
    if(CpCount == 1)
    {
        if(rootChoice == 1)
        {
            int count = 1, position1;
            struct seatNode *ptr = headSeat;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNum)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link2;
            }

            struct seatNode *temp = headSeat;
            if(position1 == 1)
            {
                headSeat = temp->link2;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link2;
                }
                struct seatNode *common = temp->link2;
                temp->link2 = common->link2;
                free(common);
                common = NULL;
            }
        }
        else if(rootChoice == 2)
        {
            int count = 1, position1;
            struct seatNode1 *ptr = headSeat1;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNum1)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link3;
            }

            struct seatNode1 *temp = headSeat1;
            if(position1 == 1)
            {
                headSeat1 = temp->link3;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link3;
                }
                struct seatNode1 *common = temp->link3;
                temp->link3 = common->link3;
                free(common);
                common = NULL;
            }
        }
    }
    else if(CpCount == 2)
    {
        if(rootChoice == 1)
        {
            int count = 1, position1;
            struct seatNodeB *ptr = headseatB;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNumB)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link2B;
            }

            struct seatNodeB *temp = headseatB;
            if(position1 == 1)
            {
                headseatB = temp->link2B;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link2B;
                }
                struct seatNodeB *common = temp->link2B;
                temp->link2B = common->link2B;
                free(common);
                common = NULL;
            }
        }

        else if(rootChoice == 2)
        {
            int count = 1, position1;
            struct seatNodeB1 *ptr = headseatB1;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNumB1)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link3B;
            }

            struct seatNodeB1 *temp = headseatB1;
            if(position1 == 1)
            {
                headseatB1 = temp->link3B;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link3B;
                }
                struct seatNodeB1 *common = temp->link3B;
                temp->link3B = common->link3B;
                free(common);
                common = NULL;
            }
        }
    }
    else if(CpCount == 3)
    {
        if(rootChoice == 1)
        {
            int count = 1, position1;
            struct seatNodeC *ptr = headseatC;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNumC)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link2C;
            }

            struct seatNodeC *temp = headseatC;
            if(position1 == 1)
            {
                headseatC = temp->link2C;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link2C;
                }
                struct seatNodeC *common = temp->link2C;
                temp->link2C = common->link2C;
                free(common);
                common = NULL;
            }
        }

        else if(rootChoice == 2)
        {
            int count = 1, position1;
            struct seatNodeC1 *ptr = headseatC1;
            while(ptr != NULL)
            {
                if(TcPos == ptr->seatNumC1)
                {
                    position1 = count;
                }
                count++;
                ptr = ptr->link3C;
            }

            struct seatNodeC1 *temp = headseatC1;
            if(position1 == 1)
            {
                headseatC1 = temp->link3C;
                free(temp);
                temp = NULL;
            }
            else
            {
                for(int i=1; i<position1-1; i++)
                {
                    temp = temp->link3C;
                }
                struct seatNodeC1 *common = temp->link3C;
                temp->link3C = common->link3C;
                free(common);
                common = NULL;
            }
        }
    }

}

void EditTicketPosition()   // Update Ticket With New Position
{
    struct profileNode *ptr = mainHead;
    if(mainHead == NULL)
    {
        printf("\n\n\t\t\t\t\tYou haven't booked any tickets yet!!!");
    }
    else
    {
        DisplayStatus();

        char cpName[100], routeN[100];
        int pos, pofT, i=1, Npos;
        printf("\n\n\t\t\t\tEnter the ticket number which ticket position you want to edit: ");
        scanf("%d", &pos);

        printf("\n\n\t\t\t\tEnter the new position for the ticket: ");
        scanf("%d", &Npos);

        int r=0;
        struct profileNode *temp3 = mainHead;
        while(temp3 != NULL)
        {
            if(Npos == temp3->position)
            {
                r=1;
            }
            temp3 = temp3->next;
        }

        if(r == 1)
        {
            printf("\n\n\t\t\t\t\tYou have already booked that ticket!!!");
        }
        else
        {
            struct profileNode *temp = mainHead;
            while(temp != NULL)
            {
                if(pos == i)
                {
                    strcpy(cpName, temp->BusCpName);
                    strcpy(routeN, temp->NameOfRoot);
                    pofT = temp->position;

                    temp->position = Npos;
                }
                i++;
                temp = temp->next;
            }

            int count, j=1;
            struct nodeBus *temp1 = head;
            while(temp1 != NULL)
            {
                if(strcmp(temp1->nameB, cpName)==0)
                {
                    count = j;
                }
                j++;
                temp1 = temp1->link;
            }

            if(count == 1)
            {
                int k=1, RootChoice;
                struct RootOfBus1 *pt = headS;
                while(pt != NULL)
                {
                    if(strcmp(pt->nameOfroot, routeN)==0)
                    {
                        RootChoice = k;
                    }
                    k++;
                    pt = pt->link1;
                }
                DeleteEditedPosition(count, RootChoice, Npos);
            }
            else if(count == 2)
            {
                int k=1, RootChoice;
                struct RootOfBus2 *pt = headH;
                while(pt != NULL)
                {
                    if(strcmp(pt->nameOfroot1, routeN)==0)
                    {
                        RootChoice = k;
                    }
                    k++;
                    pt = pt->link1B;
                }
                DeleteEditedPosition(count, RootChoice, Npos);
            }
            else if(count == 3)
            {
                int k=1, RootChoice;
                struct RootOfBus3 *pt = headE;
                while(pt != NULL)
                {
                    if(strcmp(pt->nameOfroot2, routeN)==0)
                    {
                        RootChoice = k;
                    }
                    k++;
                    pt = pt->link1C;
                }
                DeleteEditedPosition(count, RootChoice, Npos);
            }
            InsertCancelledTicket(cpName, routeN, pofT);

            printf("\n\n\t\t\t\t\tYour tickets position has successfully updated!!");
        }
    }
}

int main()
{

    struct nodeBus *n1, *n2, *n3;                   //Starts creating bus companies.
    n1 = (struct nodeBus *)malloc(sizeof(struct nodeBus));
    strcpy(n1->nameB, "SHYAMOLI PARIBAHAN");
    n1->link = NULL;

    head = n1;

    n2 = (struct nodeBus *)malloc(sizeof(struct nodeBus));
    strcpy(n2->nameB, "HANIF PARIBAHAN");
    n2->link = NULL;

    n3 = (struct nodeBus *)malloc(sizeof(struct nodeBus));
    strcpy(n3->nameB, "ENA TRAVELS");
    n3->link = NULL;

    n1->link = n2;
    n2->link = n3;                                  //End of creating bus companies.


    struct RootOfBus1 *S1, *S2;                           //Starts creating route of SHYAMOLI.

    S1 = (struct RootOfBus1 *)malloc(sizeof(struct RootOfBus1));
    strcpy(S1->nameOfroot, "Dhaka to Chittagong");
    S1->link1 = NULL;

    headS = S1;

    S2 = (struct RootOfBus1 *)malloc(sizeof(struct RootOfBus1));
    strcpy(S2->nameOfroot, "Sylhet to Dhaka");
    S2->link1 = NULL;

    S1->link1 = S2;                                        //End of creating route of SHYAMOLI.


    //Starts creating seats on SHYAMOLI's buses.

    int i = 1, n=32;                                          //creating seats of 1st bus.
    struct seatNode *s1, *s2;
    s2 = (struct seatNode *)malloc(sizeof(struct seatNode));
    s2->seatNum = i;
    s2->link2 = NULL;

    headSeat = s2;
    s1 = headSeat;

    for(i=1; i<n; i++)
    {
        s2 = (struct seatNode *)malloc(sizeof(struct seatNode));
        s2->seatNum = i+1;
        s2->link2 = NULL;

        s1->link2 = s2;
        s1 = s1->link2;
    }

    i=1;                                                       //creating seats of 2nd bus.
    struct seatNode1 *s3, *s4;
    s4 = (struct seatNode1 *)malloc(sizeof(struct seatNode1));
    s4->seatNum1 = i;
    s4->link3 = NULL;

    headSeat1 = s4;
    s3 = headSeat1;

    for(i=1; i<n; i++)
    {
        s4 = (struct seatNode1 *)malloc(sizeof(struct seatNode1));
        s4->seatNum1 = i+1;
        s4->link3 = NULL;

        s3->link3 = s4;
        s3 = s3->link3;
    }
    //End of creating seats on SHYAMOLI's buses.


    struct RootOfBus2 *S5, *S6;                                     //Starts creating route of Hanif.

    S5 = (struct RootOfBus2 *)malloc(sizeof(struct RootOfBus2));
    strcpy(S5->nameOfroot1, "Dhaka to Khulna");
    S5->link1B = NULL;

    headH = S5;

    S6 = (struct RootOfBus2 *)malloc(sizeof(struct RootOfBus2));
    strcpy(S6->nameOfroot1, "Dhaka to Thakurgaon");
    S6->link1B = NULL;

    S5->link1B = S6;                                                //Starts creating route of Hanif.


    //Starts creating seats on HANIF's buses.

    i = 1;                                                           //creating seats of 1st bus.
    struct seatNodeB *s9, *s10;
    s10 = (struct seatNodeB *)malloc(sizeof(struct seatNodeB));
    s10->seatNumB = i;
    s10->link2B = NULL;

    headseatB = s10;
    s9 = headseatB;

    for(i=1; i<n; i++)
    {
        s10 = (struct seatNodeB *)malloc(sizeof(struct seatNodeB));
        s10->seatNumB = i+1;
        s10->link2B = NULL;

        s9->link2B = s10;
        s9 = s9->link2B;
    }

    i=1;                                                              //creating seats of 2nd bus.
    struct seatNodeB1 *s11, *s12;
    s12 = (struct seatNodeB1 *)malloc(sizeof(struct seatNodeB1));
    s12->seatNumB1 = i;
    s12->link3B = NULL;

    headseatB1 = s12;
    s11 = headseatB1;

    for(i=1; i<n; i++)
    {
        s12 = (struct seatNodeB1 *)malloc(sizeof(struct seatNodeB1));
        s12->seatNumB1 = i+1;
        s12->link3B = NULL;

        s11->link3B = s12;
        s11 = s11->link3B;
    }
    //End of creating seats on HANIF's buses.



    struct RootOfBus3 *S7, *S8;                                         //Starts creating route of ENA.

    S7 = (struct RootOfBus3 *)malloc(sizeof(struct RootOfBus3));
    strcpy(S7->nameOfroot2, "Dhaka to Noakhali");
    S7->link1C = NULL;

    headE = S7;

    S8 = (struct RootOfBus3 *)malloc(sizeof(struct RootOfBus3));
    strcpy(S8->nameOfroot2, "Cumilla to Dhaka");
    S8->link1C = NULL;

    S7->link1C = S8;                                                    //End of creating route of ENA.

    //Starts creating seats on ENA's buses.
    i = 1;                                                              //creating seats of 1st bus.
    struct seatNodeC *s13, *s14;
    s14 = (struct seatNodeC *)malloc(sizeof(struct seatNodeC));
    s14->seatNumC = i;
    s14->link2C = NULL;

    headseatC = s14;
    s13 = headseatC;

    for(i=1; i<n; i++)
    {
        s14 = (struct seatNodeC *)malloc(sizeof(struct seatNodeC));
        s14->seatNumC = i+1;
        s14->link2C = NULL;

        s13->link2C = s14;
        s13 = s13->link2C;
    }

    i=1;                                                                //creating seats of 2nd bus.
    struct seatNodeC1 *s15, *s16;
    s16= (struct seatNodeC1 *)malloc(sizeof(struct seatNodeC1));
    s16->seatNumC1 = i;
    s16->link3C = NULL;

    headseatC1 = s16;
    s15 = headseatC1;

    for(i=1; i<n; i++)
    {
        s16= (struct seatNodeC1 *)malloc(sizeof(struct seatNodeC1));
        s16->seatNumC1 = i+1;
        s16->link3C = NULL;

        s15->link3C = s16;
        s15 = s15->link3C;
    }
    //End of creating seats on ENA's buses.


    int choice, j;
    for(j=0 ;; j++)
    {
        if(j == 0)
        {
            printf("\n\n\t\t\t\t =====-----=====-----=====-----=====-----=====-----===\n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t   =*=*= WELCOME TO OUR BUS RESERVATION SYSTEM =*=*=  \n");
            printf("\t\t\t\t||                                                   ||\n");
            printf("\t\t\t\t =====-----=====-----=====-----=====-----=====-----===\n\n");
        }
        else
        {
            printf("\n\n\n\t====================================================================================================\n\n");
        }

        printf("\t\t\t\t\tPlease select the options as your needs!\n\n\n");

        printf("\t\t\t\t\tPress => [1] for Viewing Bus List.\n");
        printf("\n\t\t\t\t\tPress => [2] for Booking Bus tickets.\n");
        printf("\n\t\t\t\t\tPress => [3] for Canceling booked tickets.\n");
        printf("\n\t\t\t\t\tPress => [4] for Updating tickets.\n");
        printf("\n\t\t\t\t\tPress => [5] for Viewing the status.\n");
        printf("\n\t\t\t\t\tPress => [6] for Exit the program.\n");

        printf("\n\t====================================================================================================\n\n\n");

        printf("\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);


        if(choice == 1)
        {
            int Cpname;           //Cpname -> Company Name
            Display();           // Display of BUS Company
            printf("\n\n\t\tEnter the bus company number which company's buses you want to see: ");
            scanf("%d", &Cpname);
            printf("\n");

            if(Cpname == 1)
            {
                Smdisplay(2);
            }
            else if(Cpname == 2)
            {
                Hfdisplay(2);
            }
            else if(Cpname == 3)
            {
                Enadisplay(2);
            }
        }
        if(choice == 2)
        {
            Display();          //Display of BUS Company
            Booking();
        }
        if(choice == 3)
        {
            CancelTicket();
        }
        if(choice == 4)
        {
            EditTicketPosition();
        }
        if(choice == 5)
        {
            DisplayStatus();      //Display of Profile Information
        }
        if(choice == 6)
        {
            printf("\n\n\t\t\t -----=====-----=====-----=====-----=====-----=====-----=====-----\n");
            printf("\t\t\t||                                                               ||\n");
            printf("\t\t\t   =*=*= Thanks for using our system and enjoy your travel! =*=*=  \n");
            printf("\t\t\t||                                                               ||\n");
            printf("\t\t\t -----=====-----=====-----=====-----=====-----=====-----=====-----\n\n");

            break;
        }
    }
    return(0);
}
