void __thiscall btSoftBody::initializeFaceTree(btSoftBody *this, btSoftBody *thisa)
{
  btSoftBody *v2; // ebx
  btSoftBody::Face *v3; // ebx
  btVector3 *v4; // ecx
  btVector3 *v5; // edx
  btDbvt *v6; // ecx
  int v7; // [esp+3Ch] [ebp-34h]
  int v8; // [esp+40h] [ebp-30h]
  btVector3 *ppts[3]; // [esp+44h] [ebp-2Ch] BYREF
  btDbvtAabbMm volume; // [esp+50h] [ebp-20h] BYREF

  v2 = thisa;
  btDbvt::clear((btDbvt *)this);
  v8 = 0;
  if ( thisa->m_faces.m_size > 0 )
  {
    v7 = 0;
    while ( 1 )
    {
      v3 = &v2->m_faces.m_data[v7];
      v4 = (btVector3 *)v3->m_n[1];
      v5 = (btVector3 *)v3->m_n[2];
      ppts[0] = &v3->m_n[0]->m_x;
      ppts[1] = v4 + 1;
      ppts[2] = v5 + 1;
      btDbvtAabbMm::FromPoints((const btVector3 **)ppts, &volume);
      ++v7;
      v3->m_leaf = btDbvt::insert(v6, &volume, v3);
      if ( ++v8 >= thisa->m_faces.m_size )
        break;
      v2 = thisa;
    }
  }
}
