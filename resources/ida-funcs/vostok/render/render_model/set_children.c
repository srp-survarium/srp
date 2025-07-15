void __thiscall vostok::render::render_model::set_children(
        vostok::render::render_model *this,
        vostok::render::render_surface **children_in,
        unsigned __int8 count,
        vostok::render::model_lods_descriptor *lods)
{
  int v6; // ebx
  vostok::math::aabb other; // [esp+4h] [ebp-18h] BYREF
  vostok::math::aabb *p_m_aabbox; // [esp+24h] [ebp+8h]
  vostok::render::render_surface **v9; // [esp+28h] [ebp+Ch]

  this->m_childs = children_in;
  this->m_childs_count = count;
  this->m_lods_descriptor = lods;
  if ( count )
  {
    p_m_aabbox = &this->m_aabbox;
    v9 = children_in;
    v6 = count;
    do
    {
      qmemcpy(&other, &(*v9)->m_aabbox, sizeof(other));
      vostok::math::aabb::modify(&other, p_m_aabbox);
      ++v9;
      --v6;
    }
    while ( v6 );
  }
}
