void __usercall survarium::hit_receiver::hit_receiver(survarium::hit_receiver *this@<ecx>, _DWORD *a2@<edi>)
{
  _DWORD *v2; // esi
  _DWORD *v3; // eax

  *a2 = &vostok::collision::game_object::`vftable';
  v2 = a2 + 1;
  v3 = pt3malloc(8u);
  if ( v3 )
  {
    *v3 = v2;
    v3[1] = 0;
  }
  else
  {
    v3 = 0;
  }
  *v2 = v3;
  *(_DWORD *)(*v2 + 4) = v3[1] + 1;
  *a2 = &survarium::hit_receiver::`vftable';
}
