
// Add #includes of Standard C++/C headers are encouraged to be placed here.
//
//
#ifndef GUARD_SMCPCORE_BEDROCK_CONFIG_DEBUGGING_H
#define GUARD_SMCPCORE_BEDROCK_CONFIG_DEBUGGING_H

// It's borrowed from "Windows via C/C++"
// It's a useful Reminder for Dev to Pay attention to near code lines later...
// The message will be provided while compiling.
// F.g. Input:    #pramg SMCP_REMINDER(Add implementation here later)
//      Result: X:\...\Y.cpp(XX):[<Development Reminder>] <Add implementation here later>
//
#define SMCP_REMINDER(desc)  message(__FILE__ "(" SMCP_STRINGIZE(__LINE__) "):" "\n[<Development Reminder>] " #desc)


#endif // GUARD_SMCPCORE_BEDROCK_CONFIG_DEBUGGING_H
