#include "rsa.h"

char* text = "hello";
long* keys;
long lower, upper;

void setup() {
  Serial.begin(9600);
  /*
   * I suggest not to insert a value mor of 100 into the first field 
   * of the random function for the lower variabile due to avoid errors
   */
  lower = random(100,300);
  upper = random(300,500);
  keys = generate_keys(lower, upper);
  Serial.print("Public Key:");
  Serial.print(keys[0]);
  Serial.print(keys[1]);
  Serial.print("\n");
  Serial.print("Private Key:");
  Serial.print(keys[0]);
  Serial.print(keys[2]);
  Serial.print("\n");
  //I declare the two keys: public and private
  long pubKey[2], privKey[2];
  pubKey[0] = keys[0];
  pubKey[1] = keys[1];
  privKey[0] = keys[0];
  privKey[1] = keys[2];
  //I crypt with the public and decrypt with the private
  long* chiper;
  Serial.print("original=");
  Serial.print(text);
  Serial.print("\n");
  chiper = rsa_encrypt(text, pubKey);
  Serial.print("after=");
  Serial.print(rsa_decrypt(chiper, privKey, 4));
  Serial.print("\n");
  //I crypt with private and decrypt with public
  Serial.print("original=");
  Serial.print(text);
  Serial.print("\n");
  chiper = rsa_encrypt(text, privKey);
  Serial.print("after=");
  Serial.print(rsa_decrypt(chiper, pubKey, 4));
  Serial.print("\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
