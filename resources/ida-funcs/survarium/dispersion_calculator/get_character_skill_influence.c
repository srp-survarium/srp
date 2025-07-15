int __userpurge survarium::dispersion_calculator::get_character_skill_influence@<xmm0>(
        survarium::dispersion_calculator *this@<ecx>,
        _DWORD *a2@<eax>,
        int a3@<edx>,
        float a4@<xmm0>,
        enum survarium::weapon_user_state_enum is_moving,
        bool a6,
        float a7)
{
  char v8; // cl
  int v9; // edx
  int v10; // edx
  _DWORD *v11; // eax
  _DWORD *v12; // eax

  if ( a4 > 0.0 )
    return *(_DWORD *)(a2[2] + 48);
  v8 = *(_BYTE *)(*a2 + 1108);
  if ( a3 )
  {
    v9 = a3 - 1;
    if ( v9 )
    {
      v10 = v9 - 1;
      if ( v10 )
      {
        if ( v10 == 1 )
          return *(_DWORD *)(a2[2] + 20);
        else
          return LODWORD(s_bm_current_air_resistance);
      }
      else
      {
        return *(_DWORD *)(a2[2] + 16);
      }
    }
    else
    {
      v11 = (_DWORD *)a2[2];
      if ( (_BYTE)is_moving )
      {
        if ( v8 )
          return v11[9];
        else
          return v11[8];
      }
      else if ( v8 )
      {
        return v11[7];
      }
      else
      {
        return v11[6];
      }
    }
  }
  else
  {
    v12 = (_DWORD *)a2[2];
    if ( (_BYTE)is_moving )
    {
      if ( v8 )
        return v12[3];
      else
        return v12[2];
    }
    else if ( v8 )
    {
      return v12[1];
    }
    else
    {
      return *v12;
    }
  }
}
