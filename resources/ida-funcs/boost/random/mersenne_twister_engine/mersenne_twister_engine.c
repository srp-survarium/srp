void __usercall boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253>(
        boost::random::mersenne_twister_engine<unsigned int,32,624,397,31,2567483615,11,4294967295,7,2636928640,15,4022730752,18,1812433253> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  *a2 = 5489;
  a2[624] = 1;
  do
  {
    a2[a2[624]] = a2[624] + 1812433253 * (a2[a2[624] - 1] ^ (a2[a2[624] - 1] >> 30));
    ++a2[624];
  }
  while ( a2[624] < 0x270u );
}
