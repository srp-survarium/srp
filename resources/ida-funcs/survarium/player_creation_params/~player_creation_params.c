void __usercall survarium::player_creation_params::~player_creation_params(
        survarium::player_creation_params *this@<ecx>,
        int a2@<eax>)
{
  survarium::base_player_creation_params *v3; // ecx

  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 572));
  `vector destructor iterator'(
    (char *)(a2 + 536),
    4u,
    9,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector destructor iterator'(
    (char *)(a2 + 500),
    4u,
    9,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector destructor iterator'(
    (char *)(a2 + 488),
    4u,
    3,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector destructor iterator'(
    (char *)(a2 + 464),
    4u,
    6,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::empty_hands,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 460));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 448));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 444));
  survarium::base_player_creation_params::~base_player_creation_params(
    v3,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2);
}
