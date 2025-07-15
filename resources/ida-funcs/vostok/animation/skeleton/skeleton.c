void __userpurge vostok::animation::skeleton::skeleton(
        vostok::animation::skeleton *this@<ecx>,
        vostok::resources::unmanaged_resource *a2@<esi>,
        vostok::resources::unmanaged_resource_vtbl *bones_count)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a2, 1u);
  a2[1].__vftable = bones_count;
  a2->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::animation::skeleton::`vftable';
}
