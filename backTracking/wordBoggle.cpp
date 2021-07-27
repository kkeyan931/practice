int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};

int found = false;

bool visited[100][100];

void dfs(vector<vector<char>> &board,
         int n, int m, string &word, int row, int col, int index)
{

    if (index == word.length())
    {
        found = true;
        return;
    }

    for (int i = 0; i < 8; ++i)
    {
        if ((row >= 0 && col >= 0 && row < n && col < m &&
             board[row][col] == word[index] && visited[row][col] == false))
        {

            visited[row][col] = true;

            dfs(board, n, m, word, row + dx[i], col + dy[i], index + 1);

            visited[row][col] = false;
        }
    }
}

bool wordBoggleHelper(vector<vector<char>> &board, int n, int m, string word)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == word[0])
            {
                memset(visited, false, sizeof(visited));
                found = false;
                dfs(board, n, m, word, i, j, 0);
                if (found)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{

    int n = board.size();
    int m = board[0].size();

    vector<string> result;

    for (auto &word : dictionary)
    {
        if (wordBoggleHelper(board, n, m, word))
        {
            result.push_back(word);
        }
    }

    return result;
}
