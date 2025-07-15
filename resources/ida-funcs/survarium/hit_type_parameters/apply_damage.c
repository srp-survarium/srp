void __thiscall survarium::hit_type_parameters::apply_damage(
        survarium::hit_type_parameters *this,
        float delta,
        float *time_in_ms)
{
  survarium::body_part_parameters *m_bdb_count; // ecx
  survarium::hit_type_parameters *v5; // ebx
  survarium::hit_type_parameters *i; // edi
  float v7; // xmm0_4
  survarium::hit_type_parameters *m_type; // [esp-1Ch] [ebp-30h]
  float v9; // [esp+Ch] [ebp-8h] BYREF
  int v10; // [esp+10h] [ebp-4h] BYREF

  m_bdb_count = (survarium::body_part_parameters *)this->m_bdb_count;
  v5 = (survarium::hit_type_parameters *)((char *)this + 8 * (_DWORD)m_bdb_count + 32);
  for ( i = this + 1; i != v5; i = (survarium::hit_type_parameters *)((char *)i + 8) )
  {
    v7 = *(float *)&i->m_type;
    if ( v7 > 0.0 )
    {
      v9 = v7 * delta;
      m_type = (survarium::hit_type_parameters *)this->m_type;
      v10 = 0;
      survarium::body_part_parameters::hit_by_type(
        m_bdb_count,
        (survarium::affects_threshold *)i->next,
        m_type,
        time_in_ms,
        &v9,
        (float *const)&v10,
        0,
        0,
        0);
    }
  }
}
