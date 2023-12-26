import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
data = pd.read_csv('queueing_system_results.csv')

# Extracting the data for plotting
lambda_values = data['Lambda']
L_values = data['L']
SimulatedL_values = data['SimulatedL']
Lq_values = data['Lq']
SimulatedLq_values = data['SimulatedLq']
W_values = data['W']
SimulatedW_values = data['SimulatedW']
Wq_values = data['Wq']
SimulatedWq_values = data['SimulatedWq']

# Creating four plots
fig, axs = plt.subplots(4, 1, figsize=(10, 20))

# L and SimulatedL
axs[0].plot(lambda_values, L_values, 'b-', label='L (Mathematical)')
axs[0].plot(lambda_values, SimulatedL_values, 'r-', label='L (Simulated)')
axs[0].set_title('L and SimulatedL')
axs[0].set_xlabel('Lambda')
axs[0].set_ylabel('L and SimulatedL')
axs[0].legend()

# Lq and SimulatedLq
axs[1].plot(lambda_values, Lq_values, 'b-', label='Lq (Mathematical)')
axs[1].plot(lambda_values, SimulatedLq_values, 'r-', label='Lq (Simulated)')
axs[1].set_title('Lq and SimulatedLq')
axs[1].set_xlabel('Lambda')
axs[1].set_ylabel('Lq and SimulatedLq')

axs[1].legend()

# W and SimulatedW
axs[2].plot(lambda_values, W_values, 'b-', label='W (Mathematical)')
axs[2].plot(lambda_values, SimulatedW_values, 'r-', label='W (Simulated)')
axs[2].set_title('W and SimulatedW')
axs[2].set_xlabel('Lambda')
axs[2].set_ylabel('W and SimulatedW')
axs[2].legend()
axs[2].set_xticks(range(15, 26))
# Wq and SimulatedWq
axs[3].plot(lambda_values, Wq_values, 'b-', label='Wq (Mathematical)')
axs[3].plot(lambda_values, SimulatedWq_values, 'r-', label='Wq (Simulated)')
axs[3].set_title('Wq and SimulatedWq')
axs[3].set_xlabel('Lambda')
axs[3].set_ylabel('Wq and SimulatedWq')
axs[3].legend()
axs[3].set_xticks(range(15, 26))
# Adjust layout and show the plots
plt.tight_layout()
plt.show()
