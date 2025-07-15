void __usercall vostok::render::material_effects::~material_effects(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>)
{
  --num_me_count;
  `vector destructor iterator'(
    (char *)(a2 + 40),
    4u,
    28,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
}
