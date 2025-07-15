void __thiscall vostok::render::stage_screen_image::~stage_screen_image(vostok::render::stage_screen_image *this)
{
  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage_screen_image::`vftable';
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>::~fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64>(
    (vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,64> *)this,
    &this->m_textures.m_container.m_begin);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(&this->m_decl_ptr);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_present_effect);
  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage::`vftable';
}
