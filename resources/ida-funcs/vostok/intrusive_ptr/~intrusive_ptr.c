void __thiscall vostok::intrusive_ptr<vostok::render::res_render_output const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_render_output const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_render_output const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *this)
{
  const vostok::render::res_render_output *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_render_output *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *this)
{
  const vostok::render::res_sampler_list *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *this)
{
  const vostok::render::shader_constant_table *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *this)
{
  vostok::animation::mixing::binary_tree_animation_node *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_animation_node *, _DWORD))this->m_object->~vostok::animation::mixing::binary_tree_base_node)(
        this->m_object,
        0);
  }
}


void __thiscall vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *this)
{
  survarium::game_effect *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      this->m_object->m_emitter.m_object->destroy(this->m_object->m_emitter.m_object, this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_declaration *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::render::res_shader_technique *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>((vostok::render::res_pass *)this->m_object);
  }
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  if ( this->m_object )
    --this->m_object->m_reference_count;
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(this);
}


void __thiscall vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *this)
{
  const vostok::render::res_texture_list *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)this,
        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        (vostok::render::res_pass *)this->m_object);
  }
}


void __usercall vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *this@<ecx>,
        vostok::render::hw_buffer_pool *a2@<esi>)
{
  vostok::render::untyped_buffer *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(this->m_object, a2);
  }
}
