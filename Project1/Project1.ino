int Do1 = 13;
int Vang2 = 8;
int Do2 = 12;
int Xanh2 = 10;
int Vang1 = 9;
int Xanh1 = 11;
unsigned long DoSang, XanhSang, VangSang = 5000;
void setup()
{
  pinMode(Do1, OUTPUT);
  pinMode(Do2, OUTPUT);
  pinMode(Xanh1, OUTPUT);
  pinMode(Vang2, OUTPUT);
  pinMode(Xanh2, OUTPUT);
  pinMode(Vang1, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600); 
}
void ThayDoiDen(int d1, int d2, int x1, int x2, 
                  int v1, int v2)
{
  digitalWrite(Do1, d1);
  digitalWrite(Do2, d2);
  digitalWrite(Xanh1, x1);
  digitalWrite(Xanh2, x2);
  digitalWrite(Vang1, v1);
  digitalWrite(Vang2, v2);
}
void loop()
{
  int val = analogRead(A0);
  // map(val, val1,val2,val11,val12)
  // biến trở có thể chỉnh đèn xanh sáng trong khoảng
  // 5s (val11: 5000) -> 10s (val12: 10000)
  XanhSang = map(val, 0, 1023, 5000, 10000);
  DoSang = XanhSang + VangSang;
  ThayDoiDen(HIGH, LOW, LOW, HIGH, LOW, LOW);
  delay(XanhSang);
  ThayDoiDen(HIGH, LOW, LOW, LOW, LOW, HIGH);
  delay(VangSang);
  ThayDoiDen(LOW, HIGH, HIGH, LOW, LOW, LOW);
  delay(XanhSang);
  ThayDoiDen(LOW, HIGH, LOW, LOW, HIGH, LOW);
  delay(VangSang);
}
