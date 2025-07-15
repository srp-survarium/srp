void __thiscall vostok::render::render_model::set_children(
        vostok::render::render_model *this,
        vostok::render::render_surface **children_in,
        unsigned __int8 count,
        vostok::render::model_lods_descriptor *lods)
{
  vostok::render::render_surface **v4; // edx
  int v5; // esi
  float x; // xmm0_4
  __int64 v7; // [esp+8h] [ebp-48h]
  float z; // [esp+10h] [ebp-40h]
  __int64 v9; // [esp+14h] [ebp-3Ch]
  float v10; // [esp+1Ch] [ebp-34h]
  __int64 v11; // [esp+20h] [ebp-30h]
  float v12; // [esp+28h] [ebp-28h]
  _BYTE v13[12]; // [esp+2Ch] [ebp-24h]
  __int64 v14; // [esp+38h] [ebp-18h]
  __int64 v15; // [esp+40h] [ebp-10h]
  __int64 v16; // [esp+48h] [ebp-8h]

  v4 = children_in;
  this->m_childs = children_in;
  this->m_childs_count = count;
  this->m_lods_descriptor = lods;
  if ( count )
  {
    v5 = count;
    do
    {
      v14 = *(_QWORD *)&(*v4)->m_aabbox.min.x;
      v15 = *(_QWORD *)&(*v4)->m_aabbox.min.elements[2];
      v16 = *(_QWORD *)&(*v4)->m_aabbox.max.elements[1];
      if ( *(float *)&v14 <= this->m_aabbox.min.x )
        *(float *)&v7 = (*v4)->m_aabbox.min.x;
      else
        *(float *)&v7 = this->m_aabbox.min.x;
      if ( *((float *)&v14 + 1) <= this->m_aabbox.min.y )
        HIDWORD(v7) = LODWORD((*v4)->m_aabbox.min.y);
      else
        HIDWORD(v7) = LODWORD(this->m_aabbox.min.y);
      if ( *(float *)&v15 <= this->m_aabbox.min.z )
        z = (*v4)->m_aabbox.min.z;
      else
        z = this->m_aabbox.min.z;
      *(_QWORD *)&this->m_aabbox.min.x = v7;
      this->m_aabbox.min.z = z;
      if ( this->m_aabbox.max.x <= *(float *)&v14 )
        LODWORD(v9) = v14;
      else
        *(float *)&v9 = this->m_aabbox.max.x;
      if ( this->m_aabbox.max.y <= *((float *)&v14 + 1) )
        HIDWORD(v9) = HIDWORD(v14);
      else
        HIDWORD(v9) = LODWORD(this->m_aabbox.max.y);
      if ( this->m_aabbox.max.z <= *(float *)&v15 )
        v10 = *(float *)&v15;
      else
        v10 = this->m_aabbox.max.z;
      *(_QWORD *)&this->m_aabbox.max.x = v9;
      x = this->m_aabbox.min.x;
      this->m_aabbox.max.z = v10;
      if ( *((float *)&v15 + 1) <= x )
        LODWORD(v11) = HIDWORD(v15);
      else
        *(float *)&v11 = x;
      if ( *(float *)&v16 <= this->m_aabbox.min.y )
        HIDWORD(v11) = v16;
      else
        HIDWORD(v11) = LODWORD(this->m_aabbox.min.y);
      if ( *((float *)&v16 + 1) <= this->m_aabbox.min.z )
        v12 = *((float *)&v16 + 1);
      else
        v12 = this->m_aabbox.min.z;
      *(_QWORD *)&this->m_aabbox.min.x = v11;
      this->m_aabbox.min.z = v12;
      if ( this->m_aabbox.max.x <= *((float *)&v15 + 1) )
        *(_DWORD *)v13 = HIDWORD(v15);
      else
        *(float *)v13 = this->m_aabbox.max.x;
      if ( this->m_aabbox.max.y <= *(float *)&v16 )
        *(_DWORD *)&v13[4] = v16;
      else
        *(float *)&v13[4] = this->m_aabbox.max.y;
      if ( this->m_aabbox.max.z <= *((float *)&v16 + 1) )
        *(_DWORD *)&v13[8] = HIDWORD(v16);
      else
        *(float *)&v13[8] = this->m_aabbox.max.z;
      ++v4;
      --v5;
      this->m_aabbox.max = *(vostok::math::float3 *)v13;
    }
    while ( v5 );
  }
}
