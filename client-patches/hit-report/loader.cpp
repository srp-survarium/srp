// SPDX-License-Identifier: GPL-3.0-or-later
#include <windows.h>

#include <stdio.h>
#include <string.h>

namespace {

enum {
	max_path_length = 32768,
	max_command_line_length = 32768
};

bool append_argument(char* const command_line, char const* const argument)
{
	size_t const used = strlen(command_line);
	size_t const length = strlen(argument);
	if (used + length + 4 >= max_command_line_length)
		return false;

	char* destination = command_line + used;
	if (used)
		*destination++ = ' ';
	*destination++ = '"';

	for (size_t i = 0; i != length; ++i) {
		if (argument[i] == '"')
			*destination++ = '\\';
		*destination++ = argument[i];
	}

	*destination++ = '"';
	*destination = 0;
	return true;
}

bool containing_directory(char* const path)
{
	char* slash = strrchr(path, '\\');
	if (!slash)
		slash = strrchr(path, '/');
	if (!slash)
		return false;
	*slash = 0;
	return true;
}

bool sibling_dll_path(char* const output)
{
	DWORD const length = GetModuleFileNameA(NULL, output, max_path_length);
	if (!length || length >= max_path_length || !containing_directory(output))
		return false;

	char const suffix[] = "\\srp_hit_report.dll";
	if (strlen(output) + sizeof(suffix) >= max_path_length)
		return false;
	strcat(output, suffix);
	return true;
}

void fail_process(PROCESS_INFORMATION const& process, char const* const message)
{
	fprintf(stderr, "%s (Win32 error %lu)\n", message, GetLastError());
	TerminateProcess(process.hProcess, 1);
	CloseHandle(process.hThread);
	CloseHandle(process.hProcess);
}

} // namespace

int main(int const argc, char** const argv)
{
	if (argc < 2) {
		fprintf(
			stderr,
			"usage: srp_hit_report_loader.exe <survarium.exe> [game arguments...]\n"
		);
		return 2;
	}

	char game_path[max_path_length] = {0};
	if (!GetFullPathNameA(argv[1], max_path_length, game_path, NULL)) {
		fprintf(stderr, "could not resolve game path\n");
		return 1;
	}

	char dll_path[max_path_length] = {0};
	if (!sibling_dll_path(dll_path) || GetFileAttributesA(dll_path) == INVALID_FILE_ATTRIBUTES) {
		fprintf(stderr, "srp_hit_report.dll must be next to the loader\n");
		return 1;
	}

	char working_directory[max_path_length] = {0};
	strcpy(working_directory, game_path);
	if (!containing_directory(working_directory)) {
		fprintf(stderr, "could not determine the game directory\n");
		return 1;
	}

	char command_line[max_command_line_length] = {0};
	for (int i = 1; i != argc; ++i) {
		if (!append_argument(command_line, argv[i])) {
			fprintf(stderr, "game command line is too long\n");
			return 1;
		}
	}

	STARTUPINFOA startup = {0};
	startup.cb = sizeof(startup);
	PROCESS_INFORMATION process = {0};
	if (!CreateProcessA(
			game_path,
			command_line,
			NULL,
			NULL,
			FALSE,
			CREATE_SUSPENDED,
			NULL,
			working_directory,
			&startup,
			&process
		)) {
		fprintf(stderr, "could not start Survarium (Win32 error %lu)\n", GetLastError());
		return 1;
	}

	size_t const dll_path_size = strlen(dll_path) + 1;
	void* const remote_path = VirtualAllocEx(
		process.hProcess,
		NULL,
		dll_path_size,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_READWRITE
	);
	if (!remote_path) {
		fail_process(process, "could not allocate the remote DLL path");
		return 1;
	}

	if (!WriteProcessMemory(
			process.hProcess,
			remote_path,
			dll_path,
			dll_path_size,
			NULL
		)) {
		VirtualFreeEx(process.hProcess, remote_path, 0, MEM_RELEASE);
		fail_process(process, "could not write the remote DLL path");
		return 1;
	}

	FARPROC const load_library = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
	HANDLE const injection_thread = CreateRemoteThread(
		process.hProcess,
		NULL,
		0,
		reinterpret_cast<LPTHREAD_START_ROUTINE>(load_library),
		remote_path,
		0,
		NULL
	);
	if (!injection_thread) {
		VirtualFreeEx(process.hProcess, remote_path, 0, MEM_RELEASE);
		fail_process(process, "could not create the injection thread");
		return 1;
	}

	WaitForSingleObject(injection_thread, INFINITE);
	DWORD injected_module = 0;
	GetExitCodeThread(injection_thread, &injected_module);
	CloseHandle(injection_thread);
	VirtualFreeEx(process.hProcess, remote_path, 0, MEM_RELEASE);

	if (!injected_module) {
		fail_process(process, "the hit-report DLL rejected the client");
		return 1;
	}

	if (ResumeThread(process.hThread) == static_cast<DWORD>(-1)) {
		fail_process(process, "could not resume Survarium");
		return 1;
	}

	CloseHandle(process.hThread);
	CloseHandle(process.hProcess);
	return 0;
}
