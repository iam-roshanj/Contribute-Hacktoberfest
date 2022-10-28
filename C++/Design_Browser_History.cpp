/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

    BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

*/

// Stack based approach
// TC -  Constructor & visit functions- O(1), back & forward functions - O(steps)
// SC - O(N)

class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    visit(homepage);
  }

  void visit(string url) {
    history.push(url);
    future = stack<string>();
  }

  string back(int steps) {
    while (history.size() > 1 && steps-- > 0)
      future.push(history.top()), history.pop();
    return history.top();
  }

  string forward(int steps) {
    while (!future.empty() && steps-- > 0)
      history.push(future.top()), future.pop();
    return history.top();
  }

 private:
  stack<string> history;
  stack<string> future;
};
