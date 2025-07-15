void __thiscall vostok::particle::particle_system::load_binary(
        vostok::particle::particle_system *this,
        vostok::mutable_buffer *buffer)
{
  unsigned __int8 *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *p_m_emitters_array; // ecx
  const vostok::variant<32> **v5; // eax
  const vostok::variant<32> **v7; // [esp+1Ch] [ebp-60h]
  vostok::particle::particle_emitter *v8; // [esp+38h] [ebp-44h]
  _DWORD *v9; // [esp+3Ch] [ebp-40h]
  int m_material_name; // [esp+40h] [ebp-3Ch]
  unsigned int ii; // [esp+44h] [ebp-38h]
  vostok::particle::particle_system_lod *v12; // [esp+48h] [ebp-34h]
  unsigned int n; // [esp+4Ch] [ebp-30h]
  unsigned int m; // [esp+50h] [ebp-2Ch]
  unsigned int k; // [esp+58h] [ebp-24h]
  vostok::particle::particle_system_lod *v16; // [esp+5Ch] [ebp-20h]
  unsigned int j; // [esp+60h] [ebp-1Ch]
  unsigned int emitter_index; // [esp+68h] [ebp-14h]
  vostok::particle::particle_system_lod *lod; // [esp+6Ch] [ebp-10h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *i; // [esp+70h] [ebp-Ch]
  unsigned int lod_index; // [esp+74h] [ebp-8h]
  vostok::particle::particle_system_lod *init_lod; // [esp+78h] [ebp-4h]

  v2 = (unsigned __int8 *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                            (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                            (int)buffer);
  vostok::memory::copy((unsigned __int8 *)&this->m_num_lods, 4u, v2, 4u);
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)4, buffer);
  this->m_lods.pointer = (vostok::particle::particle_system_lod *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                                    v3,
                                                                    (int)buffer);
  init_lod = this->m_lods.pointer;
  for ( lod_index = 0; lod_index < this->m_num_lods; ++lod_index )
  {
    v9 = operator new(0x20u, init_lod++);
    if ( v9 )
    {
      *v9 = 0;
      v9[1] = 0;
      v9[2] = 0;
      v9[3] = 0;
    }
  }
  vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)(32 * this->m_num_lods), buffer);
  for ( i = 0;
        (unsigned int)i < this->m_num_lods;
        i = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)((char *)i + 1) )
  {
    lod = &this->m_lods.pointer[(_DWORD)i];
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(i, (int)buffer);
    p_m_emitters_array = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)&lod->m_emitters_array;
    lod->m_emitters_array.pointer = (vostok::particle::particle_emitter *)v7;
    for ( emitter_index = 0; emitter_index < lod->m_num_emitters; ++emitter_index )
    {
      v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             p_m_emitters_array,
             (int)buffer);
      v8 = (vostok::particle::particle_emitter *)operator new(0x170u, v5);
      if ( v8 )
        vostok::particle::particle_emitter::particle_emitter(v8);
      vostok::mutable_buffer::operator+=((vostok::mutable_buffer *)0x170, buffer);
      p_m_emitters_array = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(emitter_index + 1);
    }
  }
  for ( j = 0; j < this->m_num_lods; ++j )
  {
    v16 = &this->m_lods.pointer[j];
    for ( k = 0; k < v16->m_num_emitters; ++k )
      vostok::particle::particle_emitter::load_binary(&v16->m_emitters_array.pointer[k], buffer);
  }
  for ( m = 0; m < this->m_num_lods; ++m )
    vostok::particle::particle_system::load_lod_actions_binary(this, &this->m_lods.pointer[m], buffer);
  for ( n = 0; n < this->m_num_lods; ++n )
  {
    v12 = &this->m_lods.pointer[n];
    for ( ii = 0; ii < v12->m_num_emitters; ++ii )
    {
      m_material_name = (int)v12->m_emitters_array.pointer[ii].m_material_name;
      *(_DWORD *)(m_material_name + 328) = vostok::particle::particle_system::index_to_action(
                                             this,
                                             v12,
                                             *(unsigned __int16 *)(m_material_name + 366));
    }
  }
}
