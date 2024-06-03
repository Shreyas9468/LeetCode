class MyStack {
      private Queue<Integer> que;
    public MyStack() {
         que = new LinkedList<>();
    }
    
   public void push(int x) {
    que.add(x);
        for (int i = 0; i < que.size()-1; i++){
            que.add(que.poll());
        }
    }


    public int pop() {
       return  que.poll();
    }

    public int top() {
        return que.peek();
    }

    public boolean empty() {
        return que.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */