.+^<\d+>\w+\s\d+\s\d+:\d+:\d+\s(?<type>\w+):.+(?<action>block|pass),(?<directon>in|out).+(?<proto>tcp|udp),\d+,(?<ip_a>\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}.),(?<ip_b>\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}.),(?<port_a>\d+),(?<port_b>\d+).+

Filter Log Format for pfSense 2.2
Starting with pfSense 2.2, the raw filter log output generated by pfSense for its internal filter log and the log output transmitted over syslog to remote hosts has changed. The new log format is a single line containing comma-separated values that should be much easier to parse than the previous methods that involved guessing at various layouts and string contents of log data generated by pf.

Plain text layout
In general terms, here is the content of the log file. For a more technical representation with greater detail, see the next section:

<Timestamp> <Hostname> filterlog: <CSV data>
Note

Hostname is not included in syslog data sent to remote log hosts

CSV Data has many common fields and some that vary by protocol:

Common fields:

Rule Number
Sub rule number
Anchor
Tracker - unique ID per rule, tracker ID is stored with the rule in config.xml for user added rules, or check /tmp/rules.debug
Real interface (e.g. em0)
Reason for the log entry (e.g. match)
Action taken that resulted in the log entry (e.g. block, pass)
Direction of the traffic (in/out)
IP version (4 for IPv4, 6 for IPv6)
IPv4:

TOS
ECN
TTL
ID
Offset
Flags
Protocol ID
Protocol text (tcp, udp, etc)
IPv6:

Class
Flow Label
Hop Limit
Protocol
Protocol ID
IPv4 or IPv6:

Length
Source IP
Destination IP
For TCP and UDP (Proto ID 6 or 17) on IPv4 or IPv6

Source Port
Destination Port
Data Length
TCP Only:

TCP Flags
Sequence Number
ACK
Window
URG
Options
ICMP:

ICMP Type, used to choose between the following possibilities
ICMP Echo Request/Reply

ICMP ID
ICMP Sequence
ICMP Protocol Unreachable

ICMP Destination IP
ICMP Protocol ID
ICMP Port Unreachable

ICMP Destination IP
ICMP Protocol ID
ICMP Port Number
ICMP unreachable (other), time exceeded, parameter problem, redirect, mask reply:

ICMP Description
ICMP Need Frag

ICMP Detination IP
ICMP MTU
ICMP tstamp

ICMP ID
ICMP Sequence
ICMP tstamp reply

ICMP ID
ICMP Sequence
ICMP otime
ICMP rtime
ICMP ttime
ICMP default:

ICMP Description
CARP (Protocol ID 112):

Type
TTL
VHID
Version
Advskew
Advbase
