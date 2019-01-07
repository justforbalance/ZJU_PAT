#include<cstdio>
#include<iostream>

using namespace std;
struct node_arr
{
	int data;
	int pos;
	int last_pos;
	int next_pos;
} node_arr[100010];

int main(void)
{
	int start_pos;
	int n, l;
	scanf("%d%d%d", &start_pos, &n, &l);
	int tmp_pos, tmp_data, tmp_next_pos;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &tmp_pos, &tmp_data, &tmp_next_pos);
		node_arr[tmp_pos].data = tmp_data;
		node_arr[tmp_pos].next_pos = tmp_next_pos;
		node_arr[tmp_pos].pos = tmp_pos;
		if (tmp_next_pos != -1)
		{
			node_arr[tmp_next_pos].last_pos = tmp_pos;
		}
	}

    int count = 1;
    tmp_pos = start_pos;
    while(node_arr[tmp_pos].next_pos!=-1)
    {
        ++count;
        tmp_pos = node_arr[tmp_pos].next_pos;
    }

    int circle = count / l;
	bool flag;
	if (count%l == 0)
	{
		flag = true;
	}
	else {
		flag = false;
	}

	for (int i = 0; i < circle; ++i)
	{
		//int this_circle_start;
		tmp_pos = start_pos;
		for (int j = 0; j < l - 1; ++j)
		{
			tmp_pos = node_arr[tmp_pos].next_pos;
		}
		//this_circle_start = tmp_pos;
		start_pos = node_arr[tmp_pos].next_pos;

        int next_real_startpos = start_pos;

       if(flag&&i<circle-1)
       {
            //int next_real_startpos = start_pos;
            for (int j = 0; j < l - 1; ++j)
            {
                next_real_startpos = node_arr[next_real_startpos].next_pos;
            }
            //this_circle_start = tmp_pos;
       }
        

        //tmp_pos = this_circle_start;

		for (int m = 0; m < l; ++m)
		{
			if (flag)
			{
				if (i == circle - 1 && m == l - 1)
				{
					printf("%05d %d -1\n", node_arr[tmp_pos].pos, node_arr[tmp_pos].data);
                    tmp_pos = node_arr[tmp_pos].last_pos;
					break;
				}
			}
			if (m == l - 1)
			{
				printf("%05d %d %05d\n", node_arr[tmp_pos].pos, node_arr[tmp_pos].data, next_real_startpos);
                tmp_pos = node_arr[tmp_pos].last_pos;
				break;
			}
			printf("%05d %d %05d\n", node_arr[tmp_pos].pos, node_arr[tmp_pos].data, node_arr[tmp_pos].last_pos);
			tmp_pos = node_arr[tmp_pos].last_pos;
		}
	}

	while (start_pos != -1)
	{
		if (node_arr[start_pos].next_pos == -1)
		{
			printf("%05d %d %d\n", node_arr[start_pos].pos, node_arr[start_pos].data, node_arr[start_pos].next_pos);
		}
		else
		{
			printf("%05d %d %05d\n", node_arr[start_pos].pos, node_arr[start_pos].data, node_arr[start_pos].next_pos);
		}
		start_pos = node_arr[start_pos].next_pos;
	}

	return 0;
}
