#include<iostream>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int FindSubString( char* pch )
{
    int   count  = 0;
    char  * p1   = pch;
    while ( *p1 != '\0' )
    {   
        if ( *p1 == p1[1] - 1 )
        {
            p1++;
            count++;
        }else  {
            break;
        }
    }
    int count2 = count;
    while ( *p1 != '\0' )
    {
        if ( *p1 == p1[1] + 1 )
        {
            p1++;
            count2--;
        }else  {
            break;
        }
    }
    if ( count2 == 0 )
        return(count);
    return(0);
}

void ModifyString( char* pText )
{
    char  * p1   = pText;
    char  * p2   = p1;
    while ( *p1 != '\0' )
    {
        int count = FindSubString( p1 );
        if ( count > 0 )
        {
            *p2++ = *p1;
            sprintf( p2, "%i", count );  //sprintf 把count按照%i的格式存入p2,只是存入p2并不输出到控制台
            while ( *p2 != '\0' )
            {
                p2++;
            }
            p1 += count + count + 1;
        }else  {
            *p2++ = *p1++;
        }
    }
}

string longestPalindrome(string s) {
    int len = s.size();
    int max_start = 0;
    int max_end = 0;
    int max_len = 1;
    if(len == 0)
        return s;
    for(int i = 0;i<len;i++)
    {
        for(int m = i,n= len - 1,j = n;;)
        {
            if(m > j)
            {
                if( n- i + 1 > max_len)
                {
                    max_len = n - i + 1;
                    max_start = i;
                    max_end = n;
                }
                break;     
            }
            if(s[m] == s[j])
            {
                m++;
                j--;
            }
            else
            {
                m = i;
                n--;
                j = n;
            }
        }
    }
    return s.substr(max_start,max_len);
}

string longeststr(string s)
{
    int max_len = 1,str_start = 0,str_end = 0;
    int len = s.size();
    int dp[len][len] = {0};
    for(int j = 0;j< len-1;j++)
    {
        dp[j][j] = 1;
        int end = j+1;
        if(s[j] == s[end])
        {
            dp[j][end] = 1;
            max_len = 2;
            str_start = j;
        }
    }
    dp[len-1][len-1] = 1;
    for(int i = 3;i<=len;i++)
    {
        for(int j = 0;j<= len-i;j++)
        {
            int end = j+i-1;
            if(s[j] == s[end] && dp[j+1][end-1] == 1)
            {
                dp[j][end] = 1;
                if(i > max_len)
                {
                    max_len = i;
                    str_start = j;
                }
            }
        }
    }
    
    return s.substr(str_start,max_len);
}
#include<vector>
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty())
        return false;
    int row = matrix.size();
    int lo = matrix[1].size();
    if(row==0 && lo==0)
        return false;
    for(int i = 0,j = lo-1;i<row && j>=0;)
    {
        if(matrix[i][j] > target)
            j--;
        else if(matrix[i][j] < target)
            i++;
        else if(matrix[i][j] == target)
            return true;
        
    }
    return false;
}
vector<vector<char>> board;
string word;
vector<vector<bool>> flag;
bool dfs(int current_row,int current_column,int word_num)
{
    int word_len = word.size();
    int up = current_row-1,down = current_row+1,left = current_column-1,right=current_column+1;
    flag[current_row][current_column] = true;
    if(up>=0) //上
    {
        if(board[up][current_column] == word[word_num+1] && flag[up][current_column]==false)
        {
            if(word_num+1 == word_len-1)
                return true;
            else
            {
                if(dfs(up,current_column,word_num+1))
                return true;
            }
        }
    }
    if(right<board[0].size() ) //右
    {
        if(board[current_row][right] == word[word_num+1] && flag[current_row][right]==false)
        {
            if(word_num+1 == word_len-1)
                return true;
            else
                if(dfs(current_row,right,word_num+1))
                    return true;
        }
    }
    if(down<board.size()) //下
    {
        if(board[down][current_column] == word[word_num+1] && flag[down][current_column]==false)
        {
            if(word_num+1 == word_len-1)
                return true;
            else
                if(dfs(down,current_column,word_num+1))
                    return true;
        }
    }
    if(left>=0) //左
    {
        if(board[current_row][left] == word[word_num+1] && flag[current_row][left]==false)
        {
            if(word_num+1 == word_len-1)
                return true;
            else
                if(dfs(current_row,left,word_num+1))
                    return true;
        }
    }
    return false;
}
bool exist(vector<vector<char>>& _board, string _word) 
{
    board = _board;
    word = _word;
    vector<vector<int>> first_loc;
    int row = board.size(),column = board[0].size();
    vector<vector<bool>> flag_init(row,vector<bool>(column,false));
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
        {
            if(board[i][j] == word[0])
                first_loc.push_back({i,j});
        }
    
    for(int i=0;i<first_loc.size();i++)
    {
        int first_word = 0;
        flag.clear();
        flag = flag_init;
        if(dfs(first_loc[i][0],first_loc[i][1],first_word))
            return true;
    }
    return false;
}

int findUnsortedSubarray(vector<int>& nums) {
     int len = nums.size(),start,end;
     vector<int> nums_sort = nums;
     sort(nums_sort.begin(),nums_sort.end());
     for(int i = 0;i<len;i++)
     {
         if(nums[i] != nums_sort[i])
            start = i;
        break;
     }   
     for(int j=len-1;j>=0;j--)
     {
         if(nums[j] != nums_sort[j])
            end = j;
        break;
     }   
     return (end-start+1);
    }

    int calc_sum(int i)
    {
        int sum = 0;
        while(i)
        {
            sum += i%10;
            i/= 10;
        }
        return sum;
    }

 int movingCount(int m, int n, int k) {
        int sum = 0;
        bool arry[m][n];
        arry[0][0] = true;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int ij_sum = calc_sum(i) + calc_sum(j);
                if(ij_sum <= k && i>0 && j>0)
                {   
                    if((arry[i-1][j] == true) || (arry[i][j-1] == true))
                    {    
                        sum++;
                        arry[i][j] = true;
                    }
                    else
                    {
                        arry[i][j] = false;
                    }
                    
                }
                else if(ij_sum <= k && i==0)
                {
                    sum++;
                    arry[i][j] = true;
                }    
                else if(ij_sum <= k && i>0 && j==0 && arry[i-1][j] == true)
                {
                    sum++;
                    arry[i][j] = true;
                }
                else
                {
                    arry[i][j] = false;
                }
            }
        return sum;
    }
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* deleteNode(ListNode* head, int val) {
    ListNode* prehead = new ListNode(0);
    prehead->next = head;
    ListNode* pre = prehead;
    ListNode* p = head;
    while(p!=NULL)
    {
        if(p->val == val)
        {
            pre->next = p->next;
            return prehead->next;
        }
        else
        {
            pre = p; //很奇妙的一步，虽然pre的值改变了但是pre后面的指向没变(eg.pre的地址为a,next的地址指向b,那么prehead里地址为a的next指向的也是b)，所以原prehead没变
                    //如果p->val = val,则pre->next的指向变了，那么prehead里的指向也会变
                    //pre无论怎么变，只要还在prehead的序列里那么prehead就不会变
            p = p->next;//同理，p只要一直指向next那就一直在head的序列里 head也不会变
        }
    }
    return prehead->next;
}

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* p1 = head;
    bool flag = false;
    if(head==NULL || head->next == NULL)
        return NULL;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast==NULL)
            return NULL;
        fast = fast->next;
        slow = slow->next;
        if(fast == slow)
        {
            flag = true;
            break;
        }
    }
    ListNode* p2 = fast;

    if(flag == true)
    {
        while(p1!=NULL)
        {
            if(p1 == p2)
            {
                return p1;
            }
            else
            {
                p2 = p2->next;
            }
            if(p2 == fast)
            {
                p1 = p1->next;
            }
        }
    }
    return NULL;
}
vector<int> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    vector<int> res;
    while(root != NULL)
    {
        if(root->left != NULL)
            que.push(root->left);
        if(root->right != NULL)
            que.push(root->right);
        res.push_back(root->val);
        root = que.front();
        que.pop();
    }
    return res;
}

class Solution {
    int s_len,p_len;
    vector<vector<int>> dp;
    string s,p;
public:
    bool isMatch(string _s, string _p) {
        s_len = _s.size() ;
        p_len = _p.size() ;
        s = _s;p = _p;
        dp = vector<vector<int>>(s_len+1,vector<int>(p_len+1,-1));

        return dfs(0,0);
    }
    bool dfs(int x,int y)
    {
        if(dp[x][y] != -1)
            return dp[x][y];
        if(y == p_len)
            return dp[x][y] = (x == s_len);
        bool first_match = p[y] == '.' || (s[x]==p[y]);
        if(y+1 < p_len && p[y+1] == '*')
        {
            dp[x][y] = dfs(x,y+2) || (first_match && dfs(x+1,y));
        }
        else
        {
            dp[x][y] = first_match && dfs(x+1,y+1);
        }
        return dp[x][y];
    }
};
int nthUglyNumber(int n) {
    map<int,int> ugly_map;
        int i = 1,j=7;
        while(i<7)//如果能整除2，3，5 且结果在map中则满足条件
        {
            ugly_map[i] = i;
            i++;
        }
        while(i<=n)
        {
            if(j%2==0)
            {
                if(ugly_map.find(j/2) != ugly_map.end())
                {
                    ugly_map[i] = j;
                    i++;
                }
            }
            else if(j%3==0)
            {
                if(ugly_map.find(j/3) != ugly_map.end())
                {
                    ugly_map[i] = j;
                    i++;
                }
            }
            else if(j%5==0)
            {
                if(ugly_map.find(j/5) != ugly_map.end())
                {
                    ugly_map[i] = j;
                    i++;
                }
            }
            j++;
        }

    return ugly_map[n];
}

int majorityElement(vector<int>& nums) {
    map<int,int> res;
    for(int i=0;i<nums.size();i++)
    {
        res[nums[i]]++;
    }
    int max=0;
    for(auto r:res)
    {
        max = r.second>max?r.second:max;
        if(max > nums.size())
            return r.first;
    }
    return -1;
}
int myAtoi(string str) {
    string value_str;
    for(char c:str)
    {
        if((c == '-' || c== '+') && value_str.empty())
            value_str += c;
        else if(c>='0' && c<='9' )
            value_str += c;
        else if(!value_str.empty() && c==' ')
            break;
        else if(c==' ')
            continue;
        else
            break;
        if(value_str.size()>10)
        {
            long long res = stoll(value_str);
            if(res < INT_MIN)
                return INT_MIN;
            else if(res>INT_MAX)
                return INT_MAX;
        }
    }
    if(value_str.size()==1 && (value_str[0]=='-' || value_str[0]=='+'))
        return 0;
    else if(!value_str.empty())
    {
        int res = stoi(value_str);
        return int(res);
    }
    return 0;
}
int main()
{
    myAtoi("+-2");
    vector<int> vec = {1,2,2,2,3,2,5};
    majorityElement(vec);
    nthUglyNumber(11);
    priority_queue<int,vector<int>,greater<int>> max_q;
    priority_queue<int,vector<int>,less<int>> min_q;
    int arry[5] = {7,3,4,6,2};
    for(int i=0;i<5;i++)
    {
        max_q.push(arry[i]);
        min_q.push(arry[i]);
        cout << max_q.top() << endl;
        cout << min_q.top() << endl;
    }
    Solution s;
    s.isMatch("aa","a");
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(5);
    ListNode* d = new ListNode(7);
    ListNode* head = a;
    head->next = b;
    head->next->next = c;
    head->next->next->next = d;
    head->next->next->next->next = b;
    //deleteNode(head,5);
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    levelOrder(tree);
    detectCycle(head);
    return 0;
}  