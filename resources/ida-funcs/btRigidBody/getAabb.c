void __userpurge btRigidBody::getAabb(btRigidBody *this@<ecx>, int a2@<eax>, btVector3 *aabbMin, btVector3 *aabbMax)
{
  (*(void (__thiscall **)(_DWORD, int, btVector3 *, btVector3 *))(**(_DWORD **)(a2 + 204) + 4))(
    *(_DWORD *)(a2 + 204),
    a2 + 16,
    aabbMin,
    aabbMax);
}
