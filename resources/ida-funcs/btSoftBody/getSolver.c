void (__cdecl *__usercall btSoftBody::getSolver@<eax>(
        btSoftBody::ePSolver::_ solver@<eax>))(btSoftBody *psb, float kst)
{
  int v1; // eax
  int v2; // eax

  if ( solver == Linear )
    return btSoftBody::PSolve_Links;
  v1 = solver - 1;
  if ( !v1 )
    return btSoftBody::PSolve_Anchors;
  v2 = v1 - 1;
  if ( !v2 )
    return btSoftBody::PSolve_RContacts;
  if ( v2 == 1 )
    return (void (__cdecl *)(btSoftBody *, float))btSoftBody::PSolve_SContacts;
  return 0;
}
