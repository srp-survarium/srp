void __thiscall vostok::fixed_vector<vostok::render::caster_model,2048>::~fixed_vector<vostok::render::caster_model,2048>(
        vostok::fixed_vector<vostok::render::caster_model,2048> *this)
{
  this->m_end = this->m_begin;
}


void __thiscall vostok::fixed_vector<vostok::render::geometry_batch,32>::~fixed_vector<vostok::render::geometry_batch,32>(
        vostok::fixed_vector<vostok::render::geometry_batch,32> *this)
{
  vostok::buffer_vector<vostok::render::geometry_batch>::clear(this, (int *)this);
}


void __thiscall vostok::fixed_vector<vostok::render::sun_cascade,8>::~fixed_vector<vostok::render::sun_cascade,8>(
        vostok::fixed_vector<vostok::render::sun_cascade,8> *this)
{
  vostok::render::sun_cascade *i; // eax

  for ( i = this->m_begin; i != this->m_end; ++i )
    i->rays.m_end = i->rays.m_begin;
  this->m_end = this->m_begin;
}


void __usercall vostok::fixed_vector<vostok::render::buffer_slot,128>::~fixed_vector<vostok::render::buffer_slot,128>(
        vostok::fixed_vector<vostok::render::buffer_slot,128> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; i += 21 )
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
  a2[1] = *a2;
}


void __usercall vostok::fixed_vector<vostok::render::texture_slot,128>::~fixed_vector<vostok::render::texture_slot,128>(
        vostok::fixed_vector<vostok::render::texture_slot,128> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; i += 21 )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i + 20);
  a2[1] = *a2;
}


void __usercall vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
        vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i);
  a2[1] = *a2;
}


void __usercall vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>::~fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32>(
        vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(i);
  a2[1] = *a2;
}
