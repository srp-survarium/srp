int __fastcall vostok::bit_index(const unsigned int power_of_two)
{
  return ((power_of_two & 0xAAAAAAAA) != 0)
       | (2
        * (((power_of_two & 0xCCCCCCCC) != 0)
         | (2
          * (((power_of_two & 0xF0F0F0F0) != 0)
           | (2 * (((power_of_two & 0xFF00FF00) != 0) | (2 * ((power_of_two & 0xFFFF0000) != 0))))))));
}
