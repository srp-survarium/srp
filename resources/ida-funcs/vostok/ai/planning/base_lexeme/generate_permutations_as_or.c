vostok::ai::planning::base_lexeme_ptr *__thiscall vostok::ai::planning::base_lexeme::generate_permutations_as_or(
        vostok::ai::planning::base_lexeme *this,
        vostok::ai::planning::base_lexeme_ptr *result,
        vostok::memory::stack_allocator *allocator,
        const vostok::ai::planning::base_lexeme *left)
{
  vostok::memory::stack_allocator *v4; // eax
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  const vostok::ai::planning::base_lexeme *const v7; // eax
  vostok::ai::planning::base_lexeme_ptr *v10; // [esp+Ch] [ebp-34h]
  vostok::ai::planning::base_lexeme *right; // [esp+18h] [ebp-28h]
  vostok::ai::planning::base_lexeme_ptr *v12; // [esp+1Ch] [ebp-24h]
  void *_Where; // [esp+28h] [ebp-18h]
  char v14; // [esp+30h] [ebp-10h]
  vostok::ai::planning::base_lexeme_ptr v15; // [esp+34h] [ebp-Ch] BYREF
  vostok::ai::planning::base_lexeme_ptr v16; // [esp+38h] [ebp-8h] BYREF
  vostok::ai::planning::base_lexeme *v17; // [esp+3Ch] [ebp-4h]

  v14 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::stack_allocator::malloc_impl(v4, 0x18u);
  v17 = (vostok::ai::planning::base_lexeme *)operator new(0x18u, _Where);
  if ( v17 )
  {
    v14 = 3;
    v12 = vostok::ai::planning::base_lexeme::generate_permutations(
            (vostok::ai::planning::base_lexeme *)this->m_right.m_lexeme,
            &v16,
            allocator,
            left);
    survarium::weapon_user_dead_state::finalize(v5);
    right = (vostok::ai::planning::base_lexeme *)v12->m_lexeme;
    v10 = vostok::ai::planning::base_lexeme::generate_permutations(
            (vostok::ai::planning::base_lexeme *)this->m_left.m_lexeme,
            &v15,
            allocator,
            left);
    survarium::weapon_user_dead_state::finalize(v6);
    vostok::ai::planning::base_lexeme::base_lexeme(v17, operation_type_or, v10->m_lexeme, right, 1u);
    vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, v7);
  }
  else
  {
    vostok::ai::planning::base_lexeme_ptr::base_lexeme_ptr(result, 0);
  }
  if ( (v14 & 2) != 0 )
  {
    v14 &= ~2u;
    vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&v15);
  }
  if ( (v14 & 1) != 0 )
    vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(&v16);
  return result;
}
