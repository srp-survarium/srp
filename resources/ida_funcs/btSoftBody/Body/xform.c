const btTransform *__usercall btSoftBody::Body::xform@<eax>(btSoftBody::Body *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax

  if ( (`btSoftBody::Body::xform'::`2'::`local static guard' & 1) == 0 )
  {
    `btSoftBody::Body::xform'::`2'::`local static guard' |= 1u;
    `btSoftBody::Body::xform'::`2'::identity = *btTransform::getIdentity();
  }
  v2 = a2[2];
  if ( v2 )
    return (const btTransform *)(v2 + 16);
  if ( *a2 )
    return (const btTransform *)(*a2 + 64);
  return &`btSoftBody::Body::xform'::`2'::identity;
}
