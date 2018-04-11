void conditionW(){
  if(condition == "forward"){
      Serial.print("We recieved your notification\t====\t");
      Serial.println(condition);
      msg[0] = 1;
  }else if(condition == "backward"){
      Serial.print("We recieved your notification\t====\t");
      Serial.println(condition);
      msg[0] = 2;
  }else if(condition == "stop"){
      Serial.print("We recieved your notification\t====\t");
      Serial.println(condition);
      msg[0] = 3;
     }
}

