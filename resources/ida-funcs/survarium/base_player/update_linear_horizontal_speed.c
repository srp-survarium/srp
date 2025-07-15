void __usercall survarium::base_player::update_linear_horizontal_speed(
        survarium::base_player *this@<ecx>,
        float *a2@<eax>)
{
  double v2; // st5
  double v3; // st6
  double v4; // st5

  v2 = *(float *)&byte_10E5C[(_DWORD)a2 + 8] - a2[17478];
  v3 = v2 * v2;
  v4 = *(float *)&byte_10E5C[(_DWORD)a2] - a2[17476];
  a2[189] = sqrt(v4 * v4 + v3) * 1000.0 / (double)*(unsigned int *)((char *)&loc_1111C + (_DWORD)a2);
}
