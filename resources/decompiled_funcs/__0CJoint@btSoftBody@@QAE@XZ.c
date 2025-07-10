void __usercall btSoftBody::CJoint::CJoint(btSoftBody::CJoint *this@<ecx>, int a2@<esi>)
{
  *(_DWORD *)a2 = &btSoftBody::Joint::`vftable';
  `vector constructor iterator'(
    (char *)(a2 + 16),
    0xCu,
    2,
    (void *(__thiscall *)(void *))vostok::render::vector<vostok::render::lpv_render_surface>::vector<vostok::render::lpv_render_surface>);
  *(_BYTE *)(a2 + 176) = 0;
  *(_DWORD *)a2 = &btSoftBody::CJoint::`vftable';
}
