void __usercall vostok::render::skeleton_model_instance::skeleton_model_instance(
        vostok::render::skeleton_model_instance *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *a2 = &vostok::render::skeleton_model_instance::`vftable';
  a2[66] = 0;
  a2[67] = 0;
}
