void __userpurge btCollisionObject::setActivationState(btCollisionObject *this@<ecx>, int a2@<eax>, int newState)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)(a2 + 228);
  if ( *v3 != 4 && *v3 != 5 )
    *v3 = newState;
}
