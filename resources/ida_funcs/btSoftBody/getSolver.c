void (__cdecl *__usercall btSoftBody::getSolver@<eax>(btSoftBody::eVSolver::_ solver@<eax>))(btSoftBody *, float)
{
  return solver == Linear ? btSoftBody::VSolve_Links : 0;
}


void (__cdecl *__usercall btSoftBody::getSolver@<eax>(
        btSoftBody::ePSolver::_ solver@<eax>))(btSoftBody *, float, float)
{
  void (__cdecl *result)(btSoftBody *, float, float); // eax

  switch ( solver )
  {
    case Linear:
      result = (void (__cdecl *)(btSoftBody *, float, float))btSoftBody::PSolve_Links;
      break;
    case Anchors:
      result = (void (__cdecl *)(btSoftBody *, float, float))btSoftBody::PSolve_Anchors;
      break;
    case RContacts:
      result = (void (__cdecl *)(btSoftBody *, float, float))btSoftBody::PSolve_RContacts;
      break;
    case SContacts:
      result = (void (__cdecl *)(btSoftBody *, float, float))btSoftBody::PSolve_SContacts;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
