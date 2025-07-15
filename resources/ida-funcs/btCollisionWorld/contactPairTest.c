void __userpurge btCollisionWorld::contactPairTest(
        btCollisionWorld *this@<ecx>,
        int a2@<edi>,
        btManifoldResult *colObjA,
        btCollisionObject *colObjB,
        btCollisionWorld::ContactResultCallback *resultCallback)
{
  _DWORD *v5; // esi
  void (__thiscall **v6)(_DWORD *, _DWORD); // eax
  btCollisionObject *v7; // [esp+0h] [ebp-D0h]
  btManifoldResult v8; // [esp+10h] [ebp-C0h] BYREF
  btCollisionWorld::ContactResultCallback *v9; // [esp+C0h] [ebp-10h]

  v5 = (_DWORD *)(*(int (__thiscall **)(_DWORD, btManifoldResult *, btCollisionObject *, _DWORD))(**(_DWORD **)(a2 + 24)
                                                                                                + 4))(
                   *(_DWORD *)(a2 + 24),
                   colObjA,
                   colObjB,
                   0);
  if ( v5 )
  {
    btManifoldResult::btManifoldResult(colObjA, &v8, colObjB, v7);
    v9 = resultCallback;
    v6 = (void (__thiscall **)(_DWORD *, _DWORD))*v5;
    v8.__vftable = (btManifoldResult_vtbl *)&btBridgedManifoldResult::`vftable';
    ((void (__thiscall *)(_DWORD *, btManifoldResult *, btCollisionObject *, int, btManifoldResult *))v6[1])(
      v5,
      colObjA,
      colObjB,
      a2 + 28,
      &v8);
    (*(void (__thiscall **)(_DWORD *, _DWORD))*v5)(v5, 0);
    (*(void (__thiscall **)(_DWORD, _DWORD *))(**(_DWORD **)(a2 + 24) + 56))(*(_DWORD *)(a2 + 24), v5);
  }
}
