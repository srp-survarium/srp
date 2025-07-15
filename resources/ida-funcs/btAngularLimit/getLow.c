float __usercall btAngularLimit::getLow@<st0>(btAngularLimit *this@<ecx>, float *a2@<eax>)
{
  return fmod(*a2 - a2[1], 6.283185482025146);
}
