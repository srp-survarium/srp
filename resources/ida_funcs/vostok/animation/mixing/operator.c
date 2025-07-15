vostok::animation::mixing::multiplication_lexeme *__usercall vostok::animation::mixing::operator*<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::weight_lexeme>@<eax>(
        vostok::animation::mixing::animation_lexeme *left@<eax>,
        vostok::animation::mixing::weight_lexeme *right@<ecx>)
{
  int v2; // eax
  int v3; // eax
  vostok::animation::mixing::multiplication_lexeme *v4; // esi
  vostok::animation::mixing::multiplication_lexeme **v5; // ecx
  bool v6; // zf
  vostok::animation::mixing::multiplication_lexeme v8; // [esp+8h] [ebp-24h] BYREF

  vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(&v8, left, right);
  v3 = v2 + 28;
  if ( *(_BYTE *)(v3 + 4) )
  {
    v4 = (vostok::animation::mixing::multiplication_lexeme *)(v3 - 28);
  }
  else
  {
    v5 = *(vostok::animation::mixing::multiplication_lexeme ***)v3;
    v4 = **(vostok::animation::mixing::multiplication_lexeme ***)v3;
    --v5[1];
    *v5 = v4 + 1;
    if ( v4 )
      vostok::animation::mixing::multiplication_lexeme::multiplication_lexeme(
        v4,
        (const vostok::animation::mixing::multiplication_lexeme *)(v3 - 28));
    v4->m_cloned = 1;
  }
  if ( v8.m_right.m_object )
  {
    v6 = v8.m_right.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_right.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_right.m_object,
        0);
  }
  if ( v8.m_left.m_object )
  {
    v6 = v8.m_left.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_left.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_left.m_object,
        0);
  }
  return v4;
}


vostok::animation::mixing::expression *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>@<eax>(
        vostok::animation::mixing::expression *left@<ecx>,
        vostok::animation::mixing::animation_lexeme *right@<eax>,
        vostok::animation::mixing::expression *a3)
{
  int v4; // eax
  int v5; // eax
  vostok::animation::mixing::expression *v6; // ecx
  vostok::animation::mixing::addition_lexeme **v7; // ecx
  vostok::animation::mixing::addition_lexeme *v8; // esi
  bool v9; // zf
  vostok::animation::mixing::addition_lexeme v10; // [esp+8h] [ebp-24h] BYREF

  if ( left->m_node.m_object && left->m_lexeme )
  {
    vostok::animation::mixing::addition_lexeme::addition_lexeme(&v10, left, right);
    v5 = v4 + 28;
    if ( *(_BYTE *)(v5 + 4) )
    {
      v6 = (vostok::animation::mixing::expression *)(v5 - 28);
    }
    else
    {
      v7 = *(vostok::animation::mixing::addition_lexeme ***)v5;
      v8 = **(vostok::animation::mixing::addition_lexeme ***)v5;
      --v7[1];
      *v7 = v8 + 1;
      if ( v8 )
        vostok::animation::mixing::addition_lexeme::addition_lexeme(
          v8,
          (const vostok::animation::mixing::addition_lexeme *)(v5 - 28));
      v8->m_cloned = 1;
      v6 = (vostok::animation::mixing::expression *)v8;
    }
    vostok::animation::mixing::expression::expression(v6, a3);
    if ( v10.m_right.m_object )
    {
      v9 = v10.m_right.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10.m_right.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v10.m_right.m_object,
          0);
    }
    if ( v10.m_left.m_object )
    {
      v9 = v10.m_left.m_object->m_reference_count-- == 1;
      if ( v9 )
        ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v10.m_left.m_object->~vostok::animation::mixing::binary_tree_base_node)(
          v10.m_left.m_object,
          0);
    }
    return a3;
  }
  else
  {
    vostok::animation::mixing::expression::expression(
      a3,
      (vostok::animation::mixing::base_lexeme *)right,
      (vostok::animation::mixing::animation_lexeme *)left);
    return a3;
  }
}


vostok::animation::mixing::addition_lexeme *__cdecl vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::animation_lexeme>(
        vostok::animation::mixing::animation_lexeme *left,
        vostok::animation::mixing::animation_lexeme *right)
{
  vostok::animation::mixing::addition_lexeme *v2; // eax
  vostok::animation::mixing::addition_lexeme *v3; // ecx
  vostok::animation::mixing::addition_lexeme v5; // [esp+18h] [ebp-28h] BYREF
  vostok::animation::mixing::addition_lexeme *v6; // [esp+3Ch] [ebp-4h]

  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v5, left, right);
  v6 = vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v2);
  vostok::animation::mixing::addition_lexeme::~addition_lexeme(v3, (int)&v5);
  return v6;
}


vostok::animation::mixing::addition_lexeme *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::multiplication_lexeme,vostok::animation::mixing::multiplication_lexeme>@<eax>(
        vostok::animation::mixing::multiplication_lexeme *left@<eax>,
        vostok::animation::mixing::multiplication_lexeme *right)
{
  int v2; // eax
  int v3; // eax
  vostok::animation::mixing::addition_lexeme *v4; // esi
  vostok::animation::mixing::addition_lexeme **v5; // ecx
  bool v6; // zf
  vostok::animation::mixing::addition_lexeme v8; // [esp+8h] [ebp-24h] BYREF

  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v8, left, right);
  v3 = v2 + 28;
  if ( *(_BYTE *)(v3 + 4) )
  {
    v4 = (vostok::animation::mixing::addition_lexeme *)(v3 - 28);
  }
  else
  {
    v5 = *(vostok::animation::mixing::addition_lexeme ***)v3;
    v4 = **(vostok::animation::mixing::addition_lexeme ***)v3;
    --v5[1];
    *v5 = v4 + 1;
    if ( v4 )
      vostok::animation::mixing::addition_lexeme::addition_lexeme(
        v4,
        (const vostok::animation::mixing::addition_lexeme *)(v3 - 28));
    v4->m_cloned = 1;
  }
  if ( v8.m_right.m_object )
  {
    v6 = v8.m_right.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_right.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_right.m_object,
        0);
  }
  if ( v8.m_left.m_object )
  {
    v6 = v8.m_left.m_object->m_reference_count-- == 1;
    if ( v6 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v8.m_left.m_object->~vostok::animation::mixing::binary_tree_base_node)(
        v8.m_left.m_object,
        0);
  }
  return v4;
}


vostok::animation::mixing::expression *__cdecl vostok::animation::mixing::operator+(
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::expression *left,
        vostok::animation::mixing::expression *right)
{
  vostok::animation::mixing::expression *v3; // ecx
  vostok::animation::mixing::expression *v4; // ecx
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::addition_lexeme v9; // [esp+24h] [ebp-24h] BYREF

  if ( vostok::animation::mixing::expression::is_empty(v3, left) )
  {
    vostok::animation::mixing::expression::expression(result, right);
    return result;
  }
  else
  {
    if ( vostok::animation::mixing::expression::is_empty(v4, right) )
    {
      vostok::animation::mixing::expression::expression(result, left);
    }
    else
    {
      vostok::animation::mixing::addition_lexeme::addition_lexeme(&v9, left, right);
      v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
      vostok::animation::mixing::expression::expression(v7, result);
      vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v9);
    }
    return result;
  }
}


vostok::animation::mixing::expression *__cdecl vostok::animation::mixing::operator+(
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::expression *left,
        vostok::animation::mixing::expression *right)
{
  vostok::animation::mixing::expression *v3; // ecx
  vostok::animation::mixing::expression *v4; // ecx
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::addition_lexeme v9; // [esp+24h] [ebp-2Ch] BYREF
  vostok::animation::mixing::expression right_real; // [esp+48h] [ebp-8h] BYREF

  if ( vostok::animation::mixing::expression::is_empty(v3, left) )
  {
    vostok::animation::mixing::expression::expression(result, right);
    return result;
  }
  else
  {
    if ( vostok::animation::mixing::expression::is_empty(v4, right) )
    {
      vostok::animation::mixing::expression::expression(result, left);
    }
    else
    {
      vostok::animation::mixing::expression::expression(&right_real, right);
      vostok::animation::mixing::addition_lexeme::addition_lexeme(&v9, left, &right_real);
      v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
      vostok::animation::mixing::expression::expression(v7, result);
      vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v9);
      vostok::animation::mixing::expression::~expression(&right_real);
    }
    return result;
  }
}


vostok::animation::mixing::expression *__cdecl vostok::animation::mixing::operator+(
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::expression *left,
        vostok::animation::mixing::expression *right)
{
  vostok::animation::mixing::expression *v3; // ecx
  vostok::animation::mixing::expression *v4; // ecx
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  vostok::animation::mixing::addition_lexeme *v8; // ecx
  vostok::animation::mixing::addition_lexeme v9; // [esp+18h] [ebp-34h] BYREF
  vostok::animation::mixing::expression left_real; // [esp+3Ch] [ebp-10h] BYREF
  vostok::animation::mixing::expression right_real; // [esp+44h] [ebp-8h] BYREF

  if ( vostok::animation::mixing::expression::is_empty(v3, left) )
  {
    vostok::animation::mixing::expression::expression(result, right);
    return result;
  }
  else
  {
    if ( vostok::animation::mixing::expression::is_empty(v4, right) )
    {
      vostok::animation::mixing::expression::expression(result, left);
    }
    else
    {
      vostok::animation::mixing::expression::expression(&left_real, left);
      vostok::animation::mixing::expression::expression(&right_real, right);
      vostok::animation::mixing::addition_lexeme::addition_lexeme(&v9, &left_real, &right_real);
      v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
      vostok::animation::mixing::expression::expression(v7, result);
      vostok::animation::mixing::addition_lexeme::~addition_lexeme(v8, (int)&v9);
      vostok::animation::mixing::expression::~expression(&right_real);
      vostok::animation::mixing::expression::~expression(&left_real);
    }
    return result;
  }
}


bool __usercall vostok::animation::mixing::operator<@<al>(
        const vostok::animation::mixing::animation_interval *left@<edi>,
        const vostok::animation::mixing::animation_interval *right@<esi>)
{
  vostok::animation::mixing::animation_interval *v2; // ebx
  vostok::animation::mixing::animation_interval *v3; // ebx
  BOOL v4; // eax
  float started; // [esp+4h] [ebp-4h]
  float v7; // [esp+4h] [ebp-4h]
  float v8; // [esp+4h] [ebp-4h]

  v2 = vostok::animation::mixing::animation_interval::animation(right);
  if ( vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object < v2->m_animation.m_object )
    return 1;
  v3 = vostok::animation::mixing::animation_interval::animation(right);
  v4 = v3->m_animation.m_object < vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object;
  if ( v4 > 0 )
    return 0;
  started = vostok::animation::mixing::animation_interval::start_time(left);
  if ( vostok::animation::mixing::animation_interval::start_time(right) > started )
    return 1;
  v7 = vostok::animation::mixing::animation_interval::start_time(left);
  if ( v7 > vostok::animation::mixing::animation_interval::start_time(right) )
    return 0;
  v8 = vostok::animation::mixing::animation_interval::length(left);
  return vostok::animation::mixing::animation_interval::length(right) > v8;
}


bool __usercall vostok::animation::mixing::operator<@<al>(
        const vostok::animation::mixing::n_ary_tree_weight_node *left@<edi>,
        const vostok::animation::mixing::n_ary_tree_weight_node *right@<esi>,
        vostok::animation::comparison_result_enum a3@<ecx>)
{
  vostok::animation::interpolator_comparer comparer; // [esp+8h] [ebp-4h] BYREF

  comparer.result = a3;
  left->m_interpolator->accept(left->m_interpolator, &comparer, right->m_interpolator);
  if ( comparer.result )
    return comparer.result == less;
  else
    return right->m_weight > left->m_weight;
}


bool __usercall vostok::animation::mixing::operator>@<al>(
        const vostok::animation::mixing::animation_interval *left@<edi>,
        const vostok::animation::mixing::animation_interval *right@<esi>)
{
  vostok::animation::mixing::animation_interval *v2; // ebx
  vostok::animation::mixing::animation_interval *v3; // ebx
  float started; // [esp+4h] [ebp-4h]
  float v6; // [esp+4h] [ebp-4h]
  float v7; // [esp+4h] [ebp-4h]

  v2 = vostok::animation::mixing::animation_interval::animation(right);
  if ( vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object < v2->m_animation.m_object )
    return 0;
  v3 = vostok::animation::mixing::animation_interval::animation(right);
  if ( v3->m_animation.m_object < vostok::animation::mixing::animation_interval::animation(left)->m_animation.m_object )
    return 1;
  started = vostok::animation::mixing::animation_interval::start_time(left);
  if ( started > vostok::animation::mixing::animation_interval::start_time(right) )
    return 1;
  v6 = vostok::animation::mixing::animation_interval::start_time(left);
  if ( vostok::animation::mixing::animation_interval::start_time(right) > v6 )
    return 0;
  v7 = vostok::animation::mixing::animation_interval::length(left);
  return v7 > vostok::animation::mixing::animation_interval::length(right);
}
