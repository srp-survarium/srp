void __usercall vostok::collision::set_bone_mask(
        vostok::animation::skeleton_bone *bone@<eax>,
        unsigned __int8 calc_mask@<cl>)
{
  const vostok::animation::skeleton_bone *const *p_m_parent; // eax

  while ( 1 )
  {
    bone->m_calc_mask |= calc_mask;
    p_m_parent = &bone->m_parent;
    if ( !*p_m_parent )
      break;
    bone = *p_m_parent;
  }
}
