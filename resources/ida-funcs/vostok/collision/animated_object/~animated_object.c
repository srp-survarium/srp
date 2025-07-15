void __usercall vostok::collision::animated_object::~animated_object(
        vostok::collision::animated_object *this@<ecx>,
        int a2@<esi>)
{
  int v2; // edi
  int v3; // ebx
  btCompoundShape *shape; // [esp+8h] [ebp-8h]
  _BYTE *v5; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 300);
  *(_DWORD *)a2 = &vostok::collision::animated_object::`vftable';
  shape = *(btCompoundShape **)(v2 + 52);
  v3 = a2 + 264;
  if ( v2 )
  {
    v5 = __RTCastToVoid((void **)v2);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 8))(v2, 0);
    (*(void (__thiscall **)(int, _BYTE *, const char *, const char *, int))(*(_DWORD *)v3 + 24))(
      a2 + 264,
      v5,
      "vostok::physics::destroy_animated_rigid_body",
      ".\\animated_rigid_body.cpp",
      217);
  }
  vostok::physics::destroy_animated_compound_shape((vostok::memory::base_allocator *)(a2 + 264), shape);
  *(_DWORD *)(a2 + 292) = *(_DWORD *)(a2 + 288);
  *(_DWORD *)v3 = &vostok::memory::base_allocator::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
