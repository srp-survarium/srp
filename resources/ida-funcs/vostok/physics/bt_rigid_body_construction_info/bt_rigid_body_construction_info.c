void __usercall vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(
        vostok::physics::bt_rigid_body_construction_info *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 1061997773;
  *(_DWORD *)(a2 + 28) = clear_value;
  *(_DWORD *)(a2 + 36) = 1000593162;
  *(float *)(a2 + 16) = FLOAT_0_5;
  *(_BYTE *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 40) = 1008981770;
  *(_DWORD *)(a2 + 44) = 1008981770;
  *(_DWORD *)(a2 + 48) = 1008981770;
}
