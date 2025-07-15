void __userpurge vostok::physics::bt_animated_rigid_body::bt_animated_rigid_body(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        _DWORD *a2@<esi>,
        btCompoundShape *shape,
        btRigidBody *body,
        unsigned __int16 game_material_id)
{
  char *v5; // edi
  _DWORD *v6; // eax

  v5 = (char *)(a2 + 1);
  v6 = pt3malloc((char *)8);
  if ( v6 )
  {
    *v6 = v5;
    v6[1] = 0;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)v5 = v6;
  *(_DWORD *)(*(_DWORD *)v5 + 4) = v6[1] + 1;
  a2[2] = 0;
  a2[3] = body;
  a2[4] = shape;
  *a2 = &vostok::physics::bt_animated_rigid_body::`vftable';
  *((_WORD *)a2 + 10) = 10;
  body->m_userObjectPointer = a2;
}
