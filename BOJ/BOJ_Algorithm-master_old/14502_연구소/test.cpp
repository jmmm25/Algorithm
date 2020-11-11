#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX_SIZE 8
using namespace std;

int map[MAX_SIZE][MAX_SIZE];
int resultMap[MAX_SIZE][MAX_SIZE];
int N, M;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;

typedef struct Coord
{
   int x;
   int y;
}coord;

bool allowXY(int x, int y, int d, int(*tempMap)[MAX_SIZE])
{
   int nx = x + dx[d];
   int ny = y + dy[d];

   if (nx < 0 || nx >= N || ny < 0 || ny >= M)
      return false;
   if (tempMap[nx][ny] != 0)
      return false;
   return true;
}

void BFS(int x, int y)
{
   coord XY = {x, y};
   queue<coord> q;
   q.push(XY);

   while (!q.empty())
   {
      coord cur = q.front();
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         if (allowXY(cur.x, cur.y, i, resultMap))
         {
            coord nextCur = { cur.x + dx[i], cur.y + dy[i] };
            resultMap[cur.x + dx[i]][cur.y + dy[i]] = 2;
            q.push(nextCur);
         }
      }
   }
}

void virus()
{
   memcpy(resultMap, map, sizeof(map));
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (map[i][j] == 2)
         {
            BFS(i, j);
         }
      }
   }

   int safeNum = 0;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (resultMap[i][j] == 0)
            safeNum++;
      }
   }
   ans = max(ans, safeNum);
}

void dfs(int x, int y, int cnt)
{
   if (cnt == 3)
   {
      virus();
      return;
   }

   for (int i = x; i < N; i++)
   {
      if (i != x)
      {
         for (int j = 0; j < M; j++)
         {
            if (map[i][j] == 0)
            {
               map[i][j] = 1;
               dfs(i, j, cnt + 1);
               map[i][j] = 0;
            }
         }
      }
      else
      {
         for (int j = y; j < M; j++)
         {
            if (map[i][j] == 0)
            {
               map[i][j] = 1;
               dfs(i, j, cnt + 1);
               map[i][j] = 0;
            }
         }
      }
   }
}

int main(void)
{
   scanf("%d %d", &N, &M);

   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         scanf("%d", &map[i][j]);
      }
   }

   dfs(0, 0, 0);
   /*
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (map[i][j] == 0)
         {
            map[i][j] = 1;
            dfs(i, j, 1);
            map[i][j] = 0;
         }
      }
   }
   */
   printf("%d\n", ans);
   return 0;
}
