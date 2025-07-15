int __usercall vostok::particle::domain_type_from_string@<eax>(char *name@<esi>)
{
  int v1; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax

  strstr((unsigned __int8 *)name, "Point");
  if ( v1 )
    return 0;
  strstr((unsigned __int8 *)name, "Line");
  if ( v3 )
    return 1;
  strstr((unsigned __int8 *)name, "Triangle");
  if ( v4 )
    return 2;
  strstr((unsigned __int8 *)name, "Plane");
  if ( v5 )
    return 3;
  strstr((unsigned __int8 *)name, "Box");
  if ( v6 )
    return 4;
  strstr((unsigned __int8 *)name, "Sphere");
  if ( v7 )
    return 5;
  strstr((unsigned __int8 *)name, "Cylinder");
  if ( v8 )
    return 6;
  strstr((unsigned __int8 *)name, "Cone");
  if ( v9 )
    return 7;
  strstr((unsigned __int8 *)name, "Blob");
  if ( v10 )
    return 8;
  strstr((unsigned __int8 *)name, "Disc");
  if ( v11 )
    return 9;
  strstr((unsigned __int8 *)name, "Rectangle");
  return v12 != 0 ? 0xA : 0;
}
