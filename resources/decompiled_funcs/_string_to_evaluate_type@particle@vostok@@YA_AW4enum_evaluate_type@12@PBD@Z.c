BOOL __cdecl vostok::particle::string_to_evaluate_type(const char *name)
{
  return !vostok::strings::equal(name, "Age") && vostok::strings::equal(name, "Random");
}
